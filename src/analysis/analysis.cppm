module;

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

export module analysis;

// =====================================================
// ----- ファイル読み込み（main.xec） -----
// =====================================================

export std::vector<unsigned int> xec_file_read() {
    std::ifstream file("main.xec"); // ファイルを開く

    if (!file) {
        std::cerr << "main.xec file open error" << std::endl;
        return {};
    }

    std::vector<unsigned int> file_data;
    unsigned int line;

    // ファイルから直接、スペースや改行区切りで1つずつ読み込む
    while (file >> line) {
        file_data.push_back(line); // filedata -> file_data に修正
        std::cout << line << std::endl;
    }

    return file_data;
}
// =====================================================
// ----- ファイル読み込み（main.xec_plugin） -----
// =====================================================

export std::vector<std::string> xec_plugin_read() {
    std::ifstream file("main.xec_plugin"); // ファイルを開く

    if (!file) {
        std::cerr << "main.xec_plugin file open error" << std::endl;
        return {};
    }

    std::vector<std::string> tokens;
    std::string token;

    // スペースや改行区切りで1単語ずつ読み込んで push_back する
    while (file >> token) {
        tokens.push_back(token);
        std::cout << token << std::endl;
    }

    return tokens;
}


// =====================================================
// ----- ファイルの解析 （main.xec, main.xec_plugin） -----
// =====================================================

export std::vector<std::string> xec_file_analysis(const std::vector<unsigned int>& xec, const std::vector<std::string>& plugin) {
    std::vector<std::string> analysis_result;

    return {};
}

