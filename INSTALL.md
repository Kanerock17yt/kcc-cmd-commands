# Installation Guide

Follow these steps to deploy the pre-compiled `timeused.exe` file so you can call it from any folder inside Command Prompt.

## Step 1: Deploy the Executable
1. Download the pre-compiled **`timeused.exe`** from the project releases (or grab it from the `build` directory if you compiled from source).
2. Create a dedicated folder on your computer to store your custom tools (for example: `C:\Program Files\timeused\`).
3. Move the `timeused.exe` file into that folder.

## Step 2: Add to Windows Path Environment Variable
To tell Windows where your new command lives, you need to add its directory path to your system's PATH variable:

1. Copy the full folder path where you just pasted `timeused.exe` (e.g., `C:\Program Files\timeused\`).
2. Open your Windows Start Menu, search for **"Edit the system environment variables"**, and open it.
3. Click the **Environment Variables...** button at the bottom right.
4. Under the **System variables** (or **User variables**) section, scroll down, select the **Path** variable, and click **Edit...**.
5. Click the **New** button on the right side.
6. Paste your copied folder path.
7. Click **OK** on all three open windows to save and apply your changes.

## Step 3: Test the Command
Open a brand new **Command Prompt (cmd)** window from anywhere on your PC and run:

```cmd
timeused
```

Your terminal will instantly output how long the PC has been running since its last boot cycle.
