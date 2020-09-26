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

#pragma region eins
//Reihe 1
//    { 15, 14, 13, 12, 11, 10,  9,  8,  7,  6,  5,  4,  3,  2,  1,  0},

void ES_IST(){
    setLed(15);
    setLed(14);
    setLed(12);
    setLed(11);
    setLed(10);
}

void SIND(){
    setLed(5);
    setLed(6);
    setLed(7);
    setLed(8);
}

void HALB(){
    setLed(0);
    setLed(1);
    setLed(2);
    setLed(3);
}

#pragma endregion


#pragma region zwei

//Reihe 2
//    { 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31},

void DREI_TOP(){
    setLed(16);
    setLed(17);
    setLed(18);
    setLed(19);
}

void VIER_TOP(){
    setLed(20);
    setLed(21);
    setLed(22);
    setLed(23);
}

void VIERTEL(){
    VIER_TOP();
    setLed(24);
    setLed(25);
    setLed(26);
}

void DREIVIERTEL(){
    DREI_TOP();
    VIERTEL();
}

void ACHT_TOP(){
    setLed(28);
    setLed(29);
    setLed(30);
    setLed(31);
}

#pragma endregion

#pragma region drei
//Reihe 3
//    { 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32},

void ZWOELF_TOP(){
    setLed(32);
    setLed(33);
    setLed(34);
    setLed(35);
    setLed(36);
}

void NULL_TOP(){
    setLed(40);
    setLed(39);
    setLed(38);
    setLed(37);
}

void NEUN_TOP(){
    setLed(43);
    setLed(42);
    setLed(41);
    setLed(40);
}

void ZWEI_TOP(){
    setLed(47);
    setLed(46);
    setLed(45);
    setLed(44);
}
void EIN_TOP(){
    setLed(45);
    setLed(44);
    setLed(43);
}

void EINE_TOP(){
    EINE_TOP();
    setLed(42);
}

#pragma endregion

#pragma region vier
//Reihe 4
//    { 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63},
void DREI_TOP_TWO(){
    setLed(48);
    setLed(49);
    setLed(50);
    setLed(51);
}

void SECHS_TOP(){
    setLed(52);
    setLed(53);
    setLed(54);
    setLed(55);
    setLed(56);
}

void SIEB_TOP(){
    setLed(56);
    setLed(57);
    setLed(58);
    setLed(59);
}

void SIEBEN_TOP(){
    SIEB_TOP();
    setLed(60);
    setLed(61);
}


#pragma endregion

#pragma region fünf
//Reihe 5
//    { 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64},
void ELF_TOP(){
    setLed(79);
    setLed(78);
    setLed(77);
}

void FUENF_TOP(){
    setLed(77);
    setLed(76);
    setLed(75);
    setLed(74);
}

void ZEHN_TOP(){
    setLed(73);
    setLed(72);
    setLed(71);
    setLed(70);
}

void UND(){
    setLed(66);
    setLed(65);
    setLed(64);
}
#pragma endregion

#pragma region sechs
//Reihe 6
//    { 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95},
void ZWANZIG_TOP(){
    setLed(80);
    setLed(81);
    setLed(82);
    setLed(83);
    setLed(84);
    setLed(85);
    setLed(86);
}

void DREISSIG_TOP(){
    setLed(95);
    setLed(88);
    setLed(89);
    setLed(90);
    setLed(91);
    setLed(92);
    setLed(93);
    setLed(94);
}
#pragma endregion

#pragma region sieben
//Reihe 7
//    {111,110,109,108,107,106,105,104,103,102,101,100, 99, 98, 97, 96},
void VIERZIG_TOP(){
    setLed(111);
    setLed(110);
    setLed(109);
    setLed(108);
    setLed(107);
    setLed(106);
    setLed(105);
}

void FUENFZIG_TOP(){
    setLed(96);
    setLed(97);
    setLed(98);
    setLed(99);
    setLed(100);
    setLed(101);
    setLed(102);
}
#pragma endregion

#pragma region acht
//Reihe 8
//    {112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127},
void MINUTEN_TOP(){
    setLed(112);
    setLed(113);
    setLed(114);
    setLed(115);
    setLed(116);
    setLed(117);
    setLed(118);
}

void UHR_TOP(){
    setLed(119);
    setLed(120);
    setLed(121);
}

void BIS(){
    setLed(122);
    setLed(123);
    setLed(124);
}

void VOR(){
    setLed(125);
    setLed(126);
    setLed(127);
}

#pragma endregion

#pragma region neun
//REIHE 9
//    {143,142,141,140,139,138,137,136,135,134,133,132,131,130,129,128},
void NACH(){
    setLed(143);
    setLed(142);
    setLed(141);
    setLed(140);
}

void MITTERNACHT(){
    setLed(128);
    setLed(129);
    setLed(130);
    setLed(131);
    setLed(132);
    setLed(133);
    setLed(134);
    setLed(135);
    setLed(136);
    setLed(137);
    setLed(138);
}
#pragma endregion

#pragma region zehn
//    {144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159},

void EIN_BOTTOM(){
    setLed(144);
    setLed(145);
    setLed(146);
}
void EINS_BOTTOM(){
    EIN_BOTTOM();
    setLed(147);
}

void EINE_BOTTOM(){
    setLed(148);
    setLed(149);
    setLed(150);
    setLed(151);
}

void NEUN_BOTTOM(){
    setLed(150);
    setLed(151);
    setLed(152);
    setLed(153);
}

void VIER_BOTTOM(){
    setLed(156);
    setLed(157);
    setLed(158);
    setLed(159);
}

#pragma endregion

#pragma region elf

  //  {175,174,173,172,171,170,169,168,167,166,165,164,163,162,161,160},
void ZWEI_BOTTOM(){
    setLed(175);
    setLed(174);
    setLed(173);
    setLed(172);
}

void DREI_BOTTOM(){
    setLed(171);
    setLed(170);
    setLed(169);
    setLed(168);
}

void SIEB_BOTTOM(){
    setLed(162);
    setLed(163); 
    setLed(164);
    setLed(165);
}
void SIEBEN_BOTTOM(){
    setLed(160);
    setLed(161);
    SIEB_BOTTOM();
}
#pragma endregion

#pragma region zwoelf
//    {176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191},

void FUENF_BOTTOM(){
    setLed(176);
    setLed(177);
    setLed(178);
    setLed(179);
}



void SECHS_BOTTOM(){
    setLed(187);
    setLed(188);
    setLed(189);
    setLed(190);
    setLed(191);
}
#pragma endregion

#pragma region dreizehn

//    {207,206,205,204,203,202,201,200,199,198,197,196,195,194,193,192},

void ZEHN_BOTTOM(){
    setLed(207);
    setLed(206);
    setLed(205);
    setLed(204);
}


void ACHT_BOTTOM(){
    setLed(198);
    setLed(199);
    setLed(200);
    setLed(201);
}

void UND_BOTTOM(){
    setLed(192);
    setLed(193);
    setLed(194);
}

#pragma endregion

#pragma region vierzehn
//    {208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223},
void ZWANZIG_BOTTOM(){
    setLed(208);
    setLed(209);
    setLed(210);
    setLed(211);
    setLed(212);
    setLed(213);
    setLed(214);
}

void DREISSIG_BOTTOM(){
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
void VIERZIG_BOTTOM(){
    setLed(239);
    setLed(238);
    setLed(237);
    setLed(236);
    setLed(235);
    setLed(234);
    setLed(233);
}

void FUENFZIG_BOTTOM(){
    setLed(224);
    setLed(225);
    setLed(226);
    setLed(227);
    setLed(228);
    setLed(229);
    setLed(230);
}

void ELF_BOTTOM(){
    setLed(230);
    setLed(231);
    setLed(232);
}

#pragma endregion


#pragma region sechszehn
//    {240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255}
void ZWOELF_BOTTOM(){
    setLed(240);
    setLed(241);
    setLed(242);
    setLed(243);
    setLed(244);
}

void MINUTEN_BOTTOM(){
    setLed(246);
    setLed(247);
    setLed(248);
    setLed(249);
    setLed(250);
    setLed(251);
    setLed(252);
}

void UHR_BOTTOM(){
    setLed(253);
    setLed(254);
    setLed(255);
}

#pragma endregion