#include <Arduino.h>
using namespace std;



const int matrix[16][16] ={
    { 15, 14, 13, 12, 11, 10,  9,  8,  7,  6,  5,  4,  3,  2,  1,  0},
    { 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31},
    { 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32},
    { 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63},
    { 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64},
    { 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95},
    {111,110,109,108,107,106,105,104,103,102,101,100, 99, 98, 97, 96},
    {112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127},
    {143,142,141,140,139,138,137,136,135,134,133,132,131,130,129,128},
    {144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159},
    {175,174,173,172,171,170,169,168,167,166,165,164,163,162,161,160},
    {176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191},
    {207,206,205,204,203,202,201,200,199,198,197,196,195,194,193,192},
    {208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223},
    {239,238,237,236,235,234,233,232,231,230,229,228,227,226,225,224},
    {240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255}
};

unsigned int smatrix[256] ={
     15, 14, 13, 12, 11, 10,  9,  8,  7,  6,  5,  4,  3,  2,  1,  0,
     16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
     47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32,
     48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
     79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64,
     80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
    111,110,109,108,107,106,105,104,103,102,101,100, 99, 98, 97, 96,
    112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,
    143,142,141,140,139,138,137,136,135,134,133,132,131,130,129,128,
    144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,
    175,174,173,172,171,170,169,168,167,166,165,164,163,162,161,160,
    176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,
    207,206,205,204,203,202,201,200,199,198,197,196,195,194,193,192,
    208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,
    239,238,237,236,235,234,233,232,231,230,229,228,227,226,225,224,
    240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255
};




#pragma region eins
//Reihe 1
//    { 15, 14, 13, 12, 11, 10,  9,  8,  7,  6,  5,  4,  3,  2,  1,  0},

void es_ist(){
    setLed(15);
    setLed(14);
    setLed(12);
    setLed(11);
    setLed(10);
}

void TOP_SIND(){
    setLed(5);
    setLed(6);
    setLed(7);
    setLed(8);
}



#pragma endregion


#pragma region zwei

//Reihe 2
//    { 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31},

void TOP_DREI(){
    setLed(23);
    setLed(24);
    setLed(25);
    setLed(26);
}

void TOP_VIER(){
    setLed(16);
    setLed(17);
    setLed(18);
    setLed(19);
}

void viertel(){
    TOP_VIER();
    setLed(20);
    setLed(21);
    setLed(22);
}



void TOP_ACHT(){
    setLed(28);
    setLed(29);
    setLed(30);
    setLed(31);
}

#pragma endregion

#pragma region drei
//Reihe 3
//    { 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32},

void TOP_ZWOELF(){
    setLed(32);
    setLed(33);
    setLed(34);
    setLed(35);
    setLed(36);
}



void TOP_ZWEI(){
    setLed(43);
    setLed(42);
    setLed(41);
    setLed(40);
}

void TOP_NEUN(){
    setLed(47);
    setLed(46);
    setLed(45);
    setLed(44);
}




#pragma endregion

#pragma region vier
//Reihe 4 Hier muss EIns rein!!!!
//    { 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63},


void TOP_EIN(){
    setLed(50);
    setLed(51);
    setLed(63);
}

void TOP_SECHS(){
    setLed(49);
    setLed(50);
    setLed(51);
    setLed(52);
    setLed(53);
}

void TOP_SIEB(){
    setLed(58);
    setLed(59);
    setLed(60);
    setLed(61);
}

void TOP_SIEBEN(){
    TOP_SIEB();
    setLed(62);
    setLed(63);
}


#pragma endregion

#pragma region fÃ¼nf
//Reihe 5
//    { 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64},
void TOP_ELF(){
    setLed(79);
    setLed(78);
    setLed(77);
}

void fuenf(){
    setLed(77);
    setLed(76);
    setLed(75);
    setLed(74);
}

void TOP_FUENF(){
  fuenf();
}

void zehn(){
    setLed(73);
    setLed(72);
    setLed(71);
    setLed(70);
}

void TOP_ZEHN(){
  zehn();
}

void TOP_UND(){
    setLed(66);
    setLed(65);
    setLed(64);
}
#pragma endregion

#pragma region sechs
//Reihe 6
//    { 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95},
void zwanzig(){
    setLed(81);
    setLed(82);
    setLed(83);
    setLed(84);
    setLed(85);
    setLed(86);
    setLed(87);

}

void TOP_ZWANZIG(){zwanzig();}

void dreissig(){
    setLed(88);
    setLed(89);
    setLed(90);
    setLed(91);
    setLed(92);
    setLed(93);
    setLed(94);
    setLed(95);

}

void TOP_DREISSIG(){dreissig();}
#pragma endregion

#pragma region sieben
//Reihe 7
//    {111,110,109,108,107,106,105,104,103,102,101,100, 99, 98, 97, 96},
void TOP_FUENFZIG(){
    setLed(111);
    setLed(110);
    setLed(109);
    setLed(108);
    setLed(107);
    setLed(106);
    setLed(105);
}

void TOP_VIERZIG(){
    setLed(102);
    setLed(101);
    setLed(100);
    setLed(99);
    setLed(98);
    setLed(97);
    setLed(96);
}


#pragma endregion

#pragma region acht
//Reihe 8
//    {112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127},
void TOP_MINUTEN(){
    setLed(112);
    setLed(113);
    setLed(114);
    setLed(115);
    setLed(116);
    setLed(117);
    setLed(118);
}

void TOP_UHR(){
    setLed(119);
    setLed(120);
    setLed(121);
}

void TOP_BIS(){
    setLed(122);
    setLed(123);
    setLed(124);
}

void vor(){
    setLed(125);
    setLed(126);
    setLed(127);
}

void TOP_VOR(){vor();}

#pragma endregion

#pragma region neun
//REIHE 9
//    {143,142,141,140,139,138,137,136,135,134,133,132,131,130,129,128},
void nach(){
    setLed(143);
    setLed(142);
    setLed(141);
    setLed(140);
}

void TOP_NACH(){nach();}


void halb(){
    setLed(133);
    setLed(134);

    setLed(135);
    setLed(136);
}

void TOP_HALB(){halb();}

#pragma endregion

#pragma region zehn
//    {144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159},

void h_ein(){
    setLed(144);
    setLed(145);
    setLed(146);
}

void BOTTOM_EIN(){h_ein();}
void eins(){
    h_ein();
    setLed(147);
}

void BOTTOM_EINS(){eins();}

void BOTTOM_EINE(){
    setLed(148);
    setLed(149);
    setLed(150);
    setLed(151);
}



void h_neun(){
    setLed(150);
    setLed(151);
    setLed(152);
    setLed(153);
}

void BOTTOM_NEUN(){h_neun();}

void h_vier(){
    setLed(156);
    setLed(157);
    setLed(158);
    setLed(159);
}

void BOTTOM_VIER(){h_vier();}

#pragma endregion

#pragma region elf

  //  {175,174,173,172,171,170,169,168,167,166,165,164,163,162,161,160},
void h_zwei(){
    setLed(175);
    setLed(174);
    setLed(173);
    setLed(172);
}

void BOTTOM_ZWEI(){h_zwei();}

void h_drei(){
    setLed(171);
    setLed(170);
    setLed(169);
    setLed(168);
}

void BOTTOM_DREI(){h_drei();}

void BOTTOM_SIEB(){
    setLed(162);
    setLed(163); 
    setLed(164);
    setLed(165);
}
void h_sieben(){
    setLed(160);
    setLed(161);
    BOTTOM_SIEB();
}

void BOTTOM_SIEBEN(){h_sieben();}
#pragma endregion

#pragma region zwoelf
//    {176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191},

void h_fuenf(){
    setLed(176);
    setLed(177);
    setLed(178);
    setLed(179);
}

void BOTTOM_FUENF(){h_fuenf();}



void h_sechs(){
    setLed(187);
    setLed(188);
    setLed(189);
    setLed(190);
    setLed(191);
}

void BOTTOM_SECHS(){h_sechs();}
#pragma endregion

#pragma region dreizehn

//    {207,206,205,204,203,202,201,200,199,198,197,196,195,194,193,192},

void h_zehn(){
    setLed(207);
    setLed(206);
    setLed(205);
    setLed(204);
}

void BOTTOM_ZEHN(){h_zehn();}


void h_acht(){
    setLed(198);
    setLed(199);
    setLed(200);
    setLed(201);
}

void BOTTOM_ACHT(){h_acht();}

void BOTTOM_UND(){
    setLed(192);
    setLed(193);
    setLed(194);
}

#pragma endregion

#pragma region vierzehn
//    {208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223},
void BOTTOM_ZWANZIG(){
    setLed(209);
    setLed(210);
    setLed(211);
    setLed(212);
    setLed(213);
    setLed(214);
    setLed(215);
}

void BOTTOM_DREISSIG(){
    setLed(216);
    setLed(217);
    setLed(218);
    setLed(219);
    setLed(220);
    setLed(221);
    setLed(222);
    setLed(223);
}

#pragma endregion

#pragma region fuenfzehn
//    {239,238,237,236,235,234,233,232,231,230,229,228,227,226,225,224},
void BOTTOM_VIERZIG(){
    setLed(239);
    setLed(238);
    setLed(237);
    setLed(236);
    setLed(235);
    setLed(234);
    setLed(233);
}

void BOTTOM_FUENFZIG(){
    setLed(224);
    setLed(225);
    setLed(226);
    setLed(227);
    setLed(228);
    setLed(229);
    setLed(230);
}

void h_elf(){
    setLed(230);
    setLed(231);
    setLed(232);
}

void BOTTOM_ELF(){h_elf();}

#pragma endregion


#pragma region sechszehn
//    {240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255}
void h_zwoelf(){
    setLed(240);
    setLed(241);
    setLed(242);
    setLed(243);
    setLed(244);
}

void BOTTOM_ZWOELF(){h_zwoelf();}

void MINUTEN_BOTTOM(){
    setLed(246);
    setLed(247);
    setLed(248);
    setLed(249);
    setLed(250);
    setLed(251);
    setLed(252);
}

void uhr(){
    setLed(253);
    setLed(254);
    setLed(255);
}

void BOTTOM_UHR(){uhr();}

#pragma endregion
