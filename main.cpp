#include <vector>
#include <string>
#include <iostream>

import analysis;
import graphic_main;



int main_control() {
    // main.xec ファイルの読み込み
    std::vector<unsigned int> file_line = xec_file_read();

    // main.xec_plugin ファイルの読み込み
    std::vector<std::string> plugin_line = xec_plugin_read();

    // main.xec の解析
    // std::vector<std::string> analysis_result = xec_file_analysis(file_line);

    // 解析結果を出力（デバッグ用）
    /*
    
    for (const auto& line : analysis_result) {
        std::cout << line << std::endl;
    }
    
    */


    return 0;
}

int main() {
    main_control();
    run_graphic_main();


    return 0;
}
