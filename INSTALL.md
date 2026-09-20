# Installation Guide

Follow these steps to install `timeused.exe` and run the `timeused` command from any folder in Windows Command Prompt.

## Step 1: Get the Executable

Use either a pre-compiled `timeused.exe` and `kcc.exe` from the project's releases or build it from the included `timeused.c` source.

## Step 2: Install the Executable

1. Create a permanent folder for the command, such as:

   ```text
   C:\Users\YOUR_USERNAME\Documents\kcc
   ```

2. Copy `kcc.exe` from the release download or the repository's `build` directory into that folder.
3. Create a sub folder for the commands, such as:
```text
C:\Users\YOUR_USERNAME\Documents\kcc\commands
```
4. Copy `timeused.exe` from the release download or the repository's `build\commands` directory into that folder.

## Step 3: Add the Folder to PATH

Adding the installation folder to Windows' `PATH` allows you to run `kcc` from any directory.

1. Copy the folder path that contains `kcc.exe`.
2. Open the Start menu and search for **Edit the system environment variables**.
3. Open it and click **Environment Variables...**.
4. Under **User variables** (recommended) or **System variables**, select `Path` and click **Edit...**.
5. Click **New** and paste the folder path.
6. Click **OK** to close each environment-variable window.

> If you add the entry under **System variables**, Windows may require administrator privileges.

## Step 4: Test the Command

Close any open Command Prompt windows and open a new one so it loads the updated `PATH`. Then run:

```cmd
kcc --timeused
```

The program reports the current Windows session information in a bordered display, including:

- The approximate date and time the current session started
- The uptime in days, hours, minutes, and seconds

Example format:

```text
+------------------------------------------------------------+
| Current Session Info                                       |
+------------------------------------------------------------+
| Turned On:   2026-09-20 08:30:00                           |
| Uptime:      0 days, 4 hrs, 12 mins, 5 secs                |
+------------------------------------------------------------+
```

The uptime is calculated using Windows' native `GetTickCount64` API. The executable is a Windows command-line program and has no runtime dependencies beyond Windows itself.
