#include QMK_KEYBOARD_H

bool encoder_update_kb(uint8_t index, bool clockwise){
    // if(!encoder_update_kb(index,clockwise)){
    //     return false;
    // }

    if(clockwise){
        layer_move(1);
    }else{
        layer_move(0);
    }
    return true;
}
