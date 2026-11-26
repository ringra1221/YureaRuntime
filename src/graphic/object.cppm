module;

#include <string>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <iostream>
#include <windows.h>

export module object_control;

export struct Object {
    // =============================
    // 状態
    // =============================

    std::string name;
    std::string type;

    // ポジションの指定
    int pos_x;
    int pos_y;

    // 大きさ
    int size_w;
    int size_h;

    // 回転角度
    double angle;

    // 反転
    bool flip_x;
    bool flip_y;

    // テスクチャのパス png推薦
    std::string texture;

    // 重なり順
    int layer;

    // 透明度
    int opacity;

    // 描画するか否か
    bool show;


    // =============================
    // 動き
    // =============================

    int animation_id;

    int animation_1;
    int animation_2;
    int animation_3;
    int animation_4;
    int animation_5;
    int animation_6;
    int animation_7;
    int animation_8;
};


int object_main_control() {
    
}