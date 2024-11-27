#include "command_parser_fsm.h"
#include <string.h> // Đảm bảo rằng thư viện này được bao gồm để sử dụng strlen

void command_parser_fsm() {
    // Kiểm tra lệnh từ bộ đệm
    if (index_buffer != 0) {
        int i = index_buffer - 1;

        // Kiểm tra lệnh "!RST#"
        if (i >= 4 && buffer[i] == '#' &&
            buffer[i - 1] == 'T' &&
            buffer[i - 2] == 'S' &&
            buffer[i - 3] == 'R' &&
            buffer[i - 4] == '!') {
            read_adc_flag = 1; // Đặt cờ để đọc ADC
            // Reset bộ đệm hoặc thực hiện các hành động cần thiết
            index_buffer = 0; // Đặt lại chỉ số bộ đệm sau khi xử lý lệnh
        }
        // Kiểm tra lệnh "!OK#"
        else if (i >= 3 && buffer[i] == '#' &&
                 buffer[i - 1] == 'K' &&
                 buffer[i - 2] == 'O' &&
                 buffer[i - 3] == '!') {
            read_adc_flag = 2; // Đặt cờ để gửi giá trị ADC
            // Reset bộ đệm hoặc thực hiện các hành động cần thiết
            index_buffer = 0; // Đặt lại chỉ số bộ đệm sau khi xử lý lệnh
        }
    }
}
