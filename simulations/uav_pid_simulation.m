% uav_pid_simulation.m
% Simulates PID-based angle correction curves for Roll, Pitch, and Yaw
% Author: Sujal Bafna
% Saves plot to ../docs/uav_pid_plot.png

clear; clc; close all;

% Simulation parameters
t_end = 15;     % seconds
dt = 0.01;
t = 0:dt:t_end;

% Initial disturbances (degrees)
roll0  = 72;
pitch0 = 23;
yaw0   = 41;

% Time constants chosen to match convergence behaviour
tau_roll  = 0.7;   % roll converges fastest
tau_pitch = 1.8;   % pitch medium
tau_yaw   = 3.5;   % yaw slowest

% Exponential decay model (represents PID damping)
roll  = roll0  .* exp(-t./tau_roll);
pitch = pitch0 .* exp(-t./tau_pitch);
yaw   = yaw0   .* exp(-t./tau_yaw);

% Create figure
fig = figure('Color','w');
set(fig, 'Position', [100, 100, 900, 320]); % [left bottom width height]

plot(t, roll,  'b', 'LineWidth', 2); hold on;
plot(t, pitch, 'g', 'LineWidth', 2);
plot(t, yaw,   'r', 'LineWidth', 2);

% Zero line
yline(0, '--', 'LineWidth', 1, 'Color', [0.2 0.2 0.2]);

grid on;
xlabel('Time (s)', 'FontSize', 12);
ylabel('Angle (°)', 'FontSize', 12);
title('PID-Based Angle Correction in UAV: Roll, Pitch, and Yaw Convergence', 'FontSize', 13);

legend({'Roll','Pitch','Yaw'}, 'Location','northeast');
set(gca, 'FontSize', 11, 'XLim', [0 t_end], 'YLim', [-1 75]);

% Save plot to docs/
if ~exist('../docs','dir')
    mkdir('../docs');
end
filename = fullfile('..','docs','uav_pid_plot.png');
print(fig, filename, '-dpng', '-r300'); % 300 DPI PNG
fprintf('Saved plot to: %s\n', filename);
