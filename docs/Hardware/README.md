# 🛠️ Hardware Design Artifacts

This folder contains the complete hardware design package for the **STM32 UAV Shield**, including source design files, exports for easy viewing, and supporting libraries.

---

## 📂 Folder Structure

```
docs/Hardware/
├── altium/
│   ├── UAV_STM_Sheild.PrjPCB       ← Altium project file
│   ├── UAV_STM_Sheild.SchDoc       ← Schematic document
│   └── UAV_STM_Sheild.PcbDoc       ← PCB layout document
├── exports/
│   ├── UAV_STM_Sheild_schematic.pdf ← Printable schematic (placeholder)
│   ├── Fabrication.pdf       ← PCB layout (2D view, placeholder)
│   └── UAV_STM_Sheild_pcb_3d.png    ← 3D-render PCB image (placeholder)
└── lib/
    ├── *.SchLib                     ← Schematic symbol libraries
    └── *.PcbLib                     ← PCB footprint libraries
```

---

## 🔍 How to Use These Files

- **Altium Project (`altium/`)**  
  Open the `.PrjPCB` file in **Altium Designer** to explore or modify the schematic (`.SchDoc`) and PCB layout (`.PcbDoc`).

- **Exports (`exports/`)**  
  These PDFs and images can be viewed directly on GitHub without CAD software.  
  Ideal for **admissions reviewers** or collaborators who just need a quick look at the design.

- **Libraries (`lib/`)**  
  Contains the component symbol (`.SchLib`) and footprint (`.PcbLib`) libraries used in the design.  
  These ensure the project compiles correctly in Altium and can be replicated or extended by others.

---

## 📖 Updating the Exports

When the hardware design changes:
1. Open the project in Altium Designer.  
2. Export updated schematics and PCB layouts as **PDFs**.  
3. Export a **top-view** and **3D render** as PNG images.  
4. Replace the placeholders in `exports/` with the new files (keep filenames consistent).  

---

## 🎯 Why This Matters

- **For Engineers** → Complete, portable Altium project with libraries included.  
- **For Reviewers** → Easy-to-view PDFs and images without requiring CAD tools.  
- **For You** → Professional documentation that demonstrates end-to-end hardware design skills.  

---

## ✅ Best Practices

- Keep **`altium/`** + **`lib/`** synced with the latest design files.  
- Keep **`exports/`** up to date for easy review.  
- Always version-control your design changes for traceability.  

---

