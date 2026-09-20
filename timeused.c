#include <stdio.h>
#include <time.h>
#include <windows.h>

#define BLUE "\033[38;2;151;250;255m"
#define BOLD "\033[1m"
#define RESET "\033[0m"

void enable_ansi_support() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut != INVALID_HANDLE_VALUE) {
        DWORD dwMode = 0;
        if (GetConsoleMode(hOut, &dwMode)) {
            dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
            SetConsoleMode(hOut, dwMode);
        }
    }
}

int main(void) {
    enable_ansi_support();

    // Get current uptime from GetTickCount64
    ULONGLONG uptime_ms = GetTickCount64();
    ULONGLONG total_seconds = uptime_ms / 1000ULL;

    unsigned int days = (unsigned int)(total_seconds / 86400ULL);
    unsigned int hours = (unsigned int)((total_seconds % 86400ULL) / 3600ULL);
    unsigned int minutes = (unsigned int)((total_seconds % 3600ULL) / 60ULL);
    unsigned int seconds = (unsigned int)(total_seconds % 60ULL);

    // Calculate when this session started (when the PC turned on)
    time_t current_time = time(NULL);
    time_t session_start = current_time - (time_t)total_seconds;

    struct tm timeinfo;
    char start_buffer[80];
    localtime_s(&timeinfo, &session_start);
    strftime(start_buffer, sizeof(start_buffer), "%Y-%m-%d %H:%M:%S", &timeinfo);

    // Format uptime duration string
    char uptime_buffer[80];
    snprintf(uptime_buffer, sizeof(uptime_buffer), "%u days, %u hrs, %u mins, %u secs", days, hours, minutes, seconds);

    // Render inside a clean, safe ASCII border box
    printf(BLUE "+------------------------------------------------------------+\n");
    printf("| " BOLD "Current Session Info" RESET BLUE "                                       |\n");
    printf("+------------------------------------------------------------+\n");
    printf("| " RESET BOLD "Turned On:  " BLUE "  %-42s " BLUE "  |\n", start_buffer);
    printf("| " RESET BOLD "Uptime:     " BLUE "  %-42s " BLUE "  |\n", uptime_buffer);
    printf("+------------------------------------------------------------+\n" RESET);

    return 0;
}