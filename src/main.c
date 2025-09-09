/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "pid.h"
#include "pid_config.h"


volatile int angles, delimeter;
volatile double roll, pitch, yaw;
volatile bool b0, b1, b2, b3, b4, b5,auto_control;

//SERVO
//														min		start	inter	end		max		inc
volatile float 			servo1_pos_data[6]		= 	{	0,		0,		44,		180,	180,	0.05	};	//Degrees
volatile int 			servo_postocount		= 	200;      												//200 Counts per Degree
volatile int 			servo_countoffset		= 	8999;
volatile int 			radar;
volatile int 			r1;
volatile int 			r2;
volatile int 			p1;
volatile int 			p2;




// PID controllers (for roll, pitch, yaw)
PID_Controller pid_roll;
PID_Controller pid_pitch;
PID_Controller pid_yaw;

void yaw_servo_positon(float servo_pos) // Servo for yaw (tail)
{
    pwm_duty_update(&B1, ((servo_pos*servo_postocount)+servo_countoffset), 0);
}
void pitch_servo1_positon(float servo_pos) //Servo for pitch 1
{
    pwm_duty_update(&A0, ((servo_pos*servo_postocount)+servo_countoffset), 0);
}
void pitch_servo2_positon(float servo_pos) //servo for pitch 2
{
    pwm_duty_update(&A1, ((servo_pos*servo_postocount)+servo_countoffset), 0);
}
void roll_servo1_positon(float servo_pos) // servo for roll 1
{
    pwm_duty_update(&A6, ((servo_pos*servo_postocount)+servo_countoffset), 0);
}
void roll_servo2_positon(float servo_pos) //servo for roll 2
{
    pwm_duty_update(&A7, ((servo_pos*servo_postocount)+servo_countoffset), 0);
}

void yaw_servo ()
{
	if (yaw<90 && yaw>0)
	{
		radar = (90-yaw);
	}
	else if (yaw>270 && yaw<360)
	{
		radar = (418-yaw);
	}
}

void pitch_1_servo()
{
	if(pitch<90 && pitch>0)
	{
		p1 = (90-pitch)/1;
	}
	else if(pitch>270 && pitch<360)
	{
		p1 = (451-pitch)/1;
	}
}

void pitch_2_servo()
{
	if(pitch<90 && pitch>0)
	{
		p2 = (90-pitch)/1;
	}
	else if(pitch>270 && pitch<360)
	{
		p2 = (451-pitch)/1;
	}
}

void roll_1_servo()
{
	if(roll<180 && roll>0)
	{
		r1 = (roll*1.1+90);
	}
	else if(roll>180 && roll<360)
	{
		r1 = (roll-235);
	}
}

void roll_2_servo()
{
	if(roll<180 && roll>0)
	{
		r2 = (roll*1.1+90);
	}
	else if(roll>180 && roll<360)
	{
		r2 = (roll-235);
	}
}
volatile bool value = true;
void control_loop()
{
	if(auto_control == value)
	{
        // compute dt from PID_CONFIG
        float dt = PID_DT;
        // setpoints (level flight)
        float roll_sp = 0.0f;
        float pitch_sp = 0.0f;
        float yaw_sp = 0.0f;

        // compute PID outputs (in degrees)
        float roll_out = PID_Compute(&pid_roll, roll_sp, (float)roll, dt);
        float pitch_out = PID_Compute(&pid_pitch, pitch_sp, (float)pitch, dt);
        float yaw_out = PID_Compute(&pid_yaw, yaw_sp, (float)yaw, dt);

        // map outputs to servo positions (saturation handled in PID)
        r1 = (int)roll_out;
        r2 = r1;
        p1 = (int)pitch_out;
        p2 = p1;
        radar = (int)yaw_out;

		yaw_servo_positon(radar);
		pitch_servo1_positon(p1);
		pitch_servo2_positon(p2);
		roll_servo1_positon(r1);
		roll_servo2_positon(r2);
	}
	else
	{
		return;
	}
}

int main(void)
{
    sysinit();
	__disable_irq();
	pwm_init(&A0, 0, 330, 0);
	pwm_init(&A1, 0, 330, 0);
	pwm_init(&A6, 0, 330, 0);
	pwm_init(&A7, 0, 330, 0);

    // Initialize PID controllers with gains from pid_config.h
    PID_Init(&pid_roll, PID_ROLL_KP, PID_ROLL_KI, PID_ROLL_KD, PID_OUTPUT_LIMIT);
    PID_Init(&pid_pitch, PID_PITCH_KP, PID_PITCH_KI, PID_PITCH_KD, PID_OUTPUT_LIMIT);
    PID_Init(&pid_yaw, PID_YAW_KP, PID_YAW_KI, PID_YAW_KD, PID_OUTPUT_LIMIT);

	timer_init(&timer2, (int)(1.0f/PID_DT), control_loop);

//	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	arduimu_init();
	__enable_irq();


	while(1)
	{
		  arduimu_poll();
	}
}


struct imu
arduimu = {&uart5,38400};

uint_least8_t UartWaitRxByte(USART_TypeDef * UART)
{
    uint32_t sr;

    do {
       sr = UART->SR;
       if (sr & USART_SR_ORE) {
        (void)UART->DR;  // in older USARTs with SR, ORE is cleared by reading SR and then DR
      }
     } while (!(sr & USART_SR_RXNE)) ;
    return UART->DR;
}

void arduimu_isr(){}

void arduimu_poll()
{
	uint8_t temp_data = UartWaitRxByte(arduimu.comm_protocol->uart);


    if (b0){
    	angles = (temp_data&0xFF);
    	b0=0, b1=1;
    }
    else if (b1){
    	angles |= (temp_data&0xFF)<<8;
    	roll = angles/200;
    	b1=0, b2=1;
    }
    else if (b2){
    	angles = (temp_data&0xFF);
    	b2=0, b3=1;
    }
    else if (b3){
    	angles |= (temp_data&0xFF)<<8;
    	pitch = angles/182;
    	b3=0, b4=1;
    }
    else if (b4){
    	angles = (temp_data&0xFF);
    	b4=0, b5=1;
    }
    else if (b5){
    	angles |= (temp_data&0xFF)<<8;
    	yaw = angles/200;
    	b5=0;
    }
    else{
		while(1){
			delimeter = temp_data;
			if (delimeter==111){

				b0=1;}
				break;
		}
    }
}

void arduimu_init()
{
	angles = 0;
	roll = 0.0;
	pitch = 0.0;
	yaw = 0.0;
	uart_init(arduimu.comm_protocol, 38400, arduimu_isr);
}

void Error_Handler(void)
{
  __disable_irq();
  while (1)
  {

  }
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
