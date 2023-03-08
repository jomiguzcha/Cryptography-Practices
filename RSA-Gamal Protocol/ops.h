#ifndef OPS_H_INCLUDED
#define OPS_H_INCLUDED
#include <bits/stdc++.h>
#include <sstream>
#include <NTL/ZZ.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include <winuser.h>
#include <sstream>>
#include <iostream>

using namespace sf;
using namespace NTL;
using namespace std;

static string alfabeto="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890.:,;-_";

ZZ gcd(ZZ,ZZ);
pair<ZZ,ZZ> gcdext(ZZ,ZZ);
ZZ modulo(ZZ,ZZ);
ZZ bynexpo(ZZ,string,ZZ);
ZZ inversa(ZZ,ZZ);
ZZ generare(ZZ,int);
string ZZ_to_string(ZZ);
ZZ string_to_ZZ(string);
ZZ Generar_raiz_primitiva(ZZ);
ZZ Generar_num_random(int);
string int_to_string(int);
int string_to_int(string);
string ASCII_to_string(int s);
string arreglar_1(int);
string arreglar_2(ZZ,ZZ);
string arreglar_3(ZZ,ZZ);
string rev(string);
string binario(ZZ);
string conv_binario(ZZ);
int bits(ZZ);
ZZ seed(ZZ& a,ZZ& b);
ZZ xorshiftrand(int);
ZZ generar_random(int);

#endif // OPS_H_INCLUDED
