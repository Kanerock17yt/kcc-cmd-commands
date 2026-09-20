#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <io.h>

#define VERSION "1.1.2"

void print_help() {
    printf("KCC Command Utility - Version %s\n", VERSION);
    printf("Usage:\n");
    printf("  kcc [options]\n\n");
    printf("Options:\n");
    printf("  --timeused    Runs the system uptime tool\n");
    printf("  --version     Displays the utility version\n");
    printf("  --help        Displays this command information\n");
}

void build_timeused_path(char *buffer, size_t buffer_size) {
    char exe_path[MAX_PATH];
    DWORD len = GetModuleFileNameA(NULL, exe_path, MAX_PATH);

    if (len == 0 || len >= MAX_PATH) {
        snprintf(buffer, buffer_size, "commands\\timeused.exe");
        return;
    }

    char *slash = strrchr(exe_path, '\\');
    if (slash != NULL) {
        *slash = '\0';
        snprintf(buffer, buffer_size, "%s\\commands\\timeused.exe", exe_path);
        return;
    }

    snprintf(buffer, buffer_size, "commands\\timeused.exe");
}

int main(int argc, char *argv[]) {
    char timeused_exe[MAX_PATH];

    if (argc < 2) {
        print_help();
        return 0;
    }

    if (strcmp(argv[1], "--timeused") == 0) {
        build_timeused_path(timeused_exe, sizeof(timeused_exe));

        if (_access(timeused_exe, 0) != 0) {
            printf("\n[KCC Error] Could not run '%s'. Ensure the 'build' folder is present.\n", timeused_exe);
            return 1;
        }

        char command[MAX_PATH + 8];
        snprintf(command, sizeof(command), "\"%s\"", timeused_exe);

        int result = system(command);

        if (result != 0) {
            printf("\n[KCC Error] Could not run '%s'. Ensure the 'build' folder is present.\n", timeused_exe);
            return 1;
        }
        return 0;
    }

    if (strcmp(argv[1], "--version") == 0) {
        printf("kcc version %s\n", VERSION);
        return 0;
    }
    else if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
        print_help();
        return 0;
    }

    printf("KCC Error: Unknown argument '%s'\n", argv[1]);
    print_help();
    return 1;
}
