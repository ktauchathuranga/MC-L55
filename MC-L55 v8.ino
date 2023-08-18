/*=============================================
Program : MC-L55
Author : Ashen Chathuranga
Time : 6:10 PM
Date : 7/12/2022
=============================================*/
// unit = 1200 / wpm
int timeoutTime = 10000;             // startup text timout time
int morseLedPin = 13;                // led pin
int unitTime = 80;                   // unit time in ms, if you want 15 WPM, unitTime = 1200 / 15
char encodeText [254] = "A SOS";     // should be capital
int cycleInterval = 1000;            // full loop interval
String extraText;
String coustomUT;
String coustomCI;
String coustomPin;

void dot(){
    
    digitalWrite(morseLedPin,HIGH);
    delay(unitTime);
    digitalWrite(morseLedPin,LOW);
    delay(unitTime);
}
void dash(){
    digitalWrite(morseLedPin,HIGH);
    delay(3*unitTime);
    digitalWrite(morseLedPin,LOW);
    delay(unitTime);
}
void space(){
    delay(6*unitTime); // cuz every dot and dash end with one unit, (actuall space 7 unit)
}
void letterSpace(){
    delay(unitTime*2);
}

void A(){
    dot();
    dash();
    letterSpace();
}
void B(){
    dash();
    dot();
    dot();
    dot();
    letterSpace();
}
void C(){
    dash();
    dot();
    dash();
    dot();
    letterSpace();
}
void D(){
    dash();
    dot();
    dot();
    letterSpace();
}
void E(){
    dot();
    letterSpace();
}
void LF(){
    dot();
    dot();
    dash();
    dot();
    letterSpace();
}
void G(){
    dash();
    dash();
    dot();
    letterSpace();
}
void H(){
    dot();
    dot();
    dot();
    dot();
    letterSpace();
}
void I(){
    dot();
    dot();
    letterSpace();
}
void J(){
    dot();
    dash();
    dash();
    dash();
    letterSpace();
}
void K(){
    dash();
    dot();
    dash();
    letterSpace();
}
void L(){
    dot();
    dash();
    dot();
    dot();
    letterSpace();
}
void M(){
    dash();
    dash();
    letterSpace();
}
void N(){
    dash();
    dot();
    letterSpace();
}
void O(){
    dash();
    dash();
    dash();
    letterSpace();
}
void P(){
    dot();
    dash();
    dash();
    dot();
    letterSpace();
}
void Q(){
    dash();
    dash();
    dot();
    dash();
    letterSpace();
}
void R(){
    dot();
    dash();
    dot();
    letterSpace();
}
void S(){
    dot();
    dot();
    dot();
    letterSpace();
}
void T(){
    dash();
    letterSpace();
}
void U(){
    dot();
    dot();
    dash();
    letterSpace();
}
void V(){
    dot();
    dot();
    dot();
    dash();
    letterSpace();
}
void W(){
    dot();
    dash();
    dash();
    letterSpace();
}
void X(){
    dash();
    dot();
    dot();
    dash();
    letterSpace();
}
void Y(){
    dash();
    dot();
    dash();
    dash();
    letterSpace();
}
void Z(){
    dash();
    dash();
    dot();
    dot();
    letterSpace();
}
void N0(){
    dash();
    dash();
    dash();
    dash();
    dash();
    letterSpace();
}
void N1(){
    dot();
    dash();
    dash();
    dash();
    dash();
    letterSpace();
}
void N2(){
    dot();
    dot();
    dash();
    dash();
    dash();
    letterSpace();
}
void N3(){
    dot();
    dot();
    dot();
    dash();
    dash();
    letterSpace();
}
void N4(){
    dot();
    dot();
    dot();
    dot();
    dash();
    letterSpace();
}
void N5(){
    dot();
    dot();
    dot();
    dot();
    dot();
    letterSpace();
}
void N6(){
    dash();
    dot();
    dot();
    dot();
    dot();
    letterSpace();
}
void N7(){
    dash();
    dash();
    dot();
    dot();
    dot();
    letterSpace();
}
void N8(){
    dash();
    dash();
    dash();
    dot();
    dot();
    letterSpace();
}
void N9(){
    dash();
    dash();
    dash();
    dash();
    dot();
    letterSpace();
}
void SfullStop(){
    dot();
    dash();
    dot();
    dash();
    dot();
    dash();
    letterSpace();
}
void Scolon(){
    dash();
    dash();
    dash();
    dot();
    dot();
    dot();
    letterSpace();
}
void Scomma(){
    dash();
    dash();
    dot();
    dot();
    dash();
    dash();
    letterSpace();
}
void Ssemicolon(){
    dash();
    dot();
    dash();
    dot();
    dash();
    dot();
    letterSpace();
}
void Squestion(){
    dot();
    dot();
    dash();
    dash();
    dot();
    dot();
    letterSpace();
}
void Sequal(){
    dash();
    dot();
    dot();
    dot();
    dash();
    letterSpace();
}
void Ssquotation(){
    dot();
    dash();
    dash();
    dash();
    dash();
    dot();
    letterSpace();
}
void Sslash(){
    dash();
    dot();
    dot();
    dash();
    dot();
    letterSpace();
}
void Sexclamation(){
    dash();
    dot();
    dash();
    dot();
    dash();
    dash();
    letterSpace();
}
void Shyphen(){
    dash();
    dot();
    dot();
    dot();
    dot();
    dash();
    letterSpace();
}
void Sunderscore(){
    dot();
    dot();
    dash();
    dash();
    dot();
    dash();
    letterSpace();
}
void Sdquotation(){
    dot();
    dash();
    dot();
    dot();
    dash();
    dot();
    letterSpace();
}
void Slbracket(){
    dash();
    dot();
    dash();
    dash();
    dot();
    letterSpace();
}
void Srbracket(){
    dash();
    dot();
    dash();
    dash();
    dot();
    dash();
    letterSpace();
}
void Sdollar(){
    dot();
    dot();
    dot();
    dash();
    dot();
    dot();
    dash();
    letterSpace();
}
void Sampersand(){
    dot();
    dash();
    dot();
    dot();
    dot();
    letterSpace();
}
void Sat(){
    dot();
    dash();
    dash();
    dot();
    dash();
    dot();
    letterSpace();
}
void Splus(){
    dot();
    dash();
    dot();
    dash();
    dot();
    letterSpace();
}







void setup(){
    Serial.begin(9600);
    Serial.setTimeout(timeoutTime);
    pinMode(morseLedPin,OUTPUT);
    delay(3000); //u got 3sec to upload and open Serial COM
    
    Serial.println("");
    Serial.println("  __  __  ___         _    ___ ___  ");
    Serial.println(" |  \\/  |/ __|  ___  | |  | __| __| ");
    Serial.println(" | |\\/| | (__  |___| | |__|__ \\__ \\ ");
    Serial.println(" |_|  |_|\\___|       |____|___/___/ ");
    Serial.println("                                    ");
    Serial.println("");

    
    //setting custom text msg
    Serial.print("Enter Your Custom Message (in 10sec, all letters should be lower than 253): ");
    extraText = Serial.readString();
    extraText.toUpperCase();
    if(extraText != ""){
        strcpy(encodeText, extraText.c_str());
        Serial.println(extraText);
        delay(250);
        Serial.println("");
    }else{
        Serial.println("");
        Serial.println("Skipping The Custom Message, Initializing Built-in Message");
        delay(250);
        Serial.println("");
    }
    
    //setting custom unit time(dot lenght)
    Serial.print("Enter Your Custom Unit Time in Milliseconds (in 10sec): ");
    coustomUT = Serial.readString();
    if(coustomUT != ""){
        unitTime = coustomUT.toInt();
        Serial.println(coustomUT);
        delay(250);
        Serial.println("");
    }else{
        Serial.println("");
        Serial.println("Skipping The Custom Unit Time, Initializing Built-in Unit Time");
        delay(250);
        Serial.println("");
    }
    
    //setting custom time between loops
    Serial.print("Enter Your Custom Cycle Interval in Milliseconds (in 10sec): ");
    coustomCI = Serial.readString();
    if(coustomCI != ""){
        cycleInterval = coustomCI.toInt();
        Serial.println(coustomCI);
        delay(250);
        Serial.println("");
    }else{
        Serial.println("");
        Serial.println("Skipping The Custom Cycle Interval, Initializing Built-in Cycle Interval");
        delay(250);
        Serial.println("");
    }
    
    //setting custom pin number
    Serial.print("Enter Your Custom Pin Number (in 10sec): ");
    coustomPin = Serial.readString();
    if(coustomPin != ""){
        morseLedPin = coustomPin.toInt();
        Serial.println(coustomPin);
        delay(250);
        Serial.println("");
    }else{
        Serial.println("");
        Serial.println("Skipping The Custom Pin Number, Initializing Built-in Pin Number");
        delay(250);
        Serial.println("");
    }
    
    Serial.println("Its ON AIR in,");
    Serial.println("3");
    delay(1000);
    Serial.println("2");
    delay(1000);
    Serial.println("1");
    delay(1000);
    Serial.println("Initiating....");
    Serial.println("");
    
    
}
void loop(){
    int len = strlen(encodeText);
    for (int i=0;i<len;i++) {
        char oneLetter = (encodeText[i]);
        switch(oneLetter) {
            
            case 'A': A(); Serial.print("A"); break;
            case 'B': B(); Serial.print("B"); break;
            case 'C': C(); Serial.print("C"); break;
            case 'D': D(); Serial.print("D"); break;
            case 'E': E(); Serial.print("E"); break;
            case 'F': LF(); Serial.print("F"); break;
            case 'G': G(); Serial.print("G"); break;
            case 'H': H(); Serial.print("H"); break;
            case 'I': I(); Serial.print("I"); break;
            case 'J': J(); Serial.print("J"); break;
            case 'K': K(); Serial.print("K"); break;
            case 'L': L(); Serial.print("L"); break;
            case 'M': M(); Serial.print("M"); break;
            case 'N': N(); Serial.print("N"); break;
            case 'O': O(); Serial.print("O"); break;
            case 'P': P(); Serial.print("P"); break;
            case 'Q': Q(); Serial.print("Q"); break;
            case 'R': R(); Serial.print("R"); break;
            case 'S': S(); Serial.print("S"); break;
            case 'T': T(); Serial.print("T"); break;
            case 'U': U(); Serial.print("U"); break;
            case 'V': V(); Serial.print("V"); break;
            case 'W': W(); Serial.print("W"); break;
            case 'X': X(); Serial.print("X"); break;
            case 'Y': Y(); Serial.print("Y"); break;
            case 'Z': Z(); Serial.print("Z"); break;
            case ' ': space(); Serial.print(" "); break;
            case '0': N0(); Serial.print("0"); break;
            case '1': N1(); Serial.print("1"); break;
            case '2': N2(); Serial.print("2"); break;
            case '3': N3(); Serial.print("3"); break;
            case '4': N4(); Serial.print("4"); break;
            case '5': N5(); Serial.print("5"); break;
            case '6': N6(); Serial.print("6"); break;
            case '7': N7(); Serial.print("7"); break;
            case '8': N8(); Serial.print("8"); break;
            case '9': N9(); Serial.print("9"); break;
            case '.': SfullStop(); Serial.print("."); break;
            case ':': Scolon(); Serial.print(":"); break;
            case ',': Scomma(); Serial.print(","); break;
            case ';': Ssemicolon(); Serial.print(";"); break;
            case '?': Squestion(); Serial.print("?"); break;
            case '=': Sequal(); Serial.print("="); break;
            case '\'': Ssquotation(); Serial.print("'"); break;
            case '/': Sslash(); Serial.print("/"); break;
            case '!': Sexclamation(); Serial.print("!"); break;
            case '-': Shyphen(); Serial.print("-"); break;
            case '_': Sunderscore(); Serial.print("_"); break;
            case '"': Sdquotation(); Serial.print("\""); break;
            case '(': Slbracket(); Serial.print("("); break;
            case ')': Srbracket(); Serial.print(")"); break;
            case '$': Sdollar(); Serial.print("$"); break;
            case '&': Sampersand(); Serial.print("&"); break;
            case '@': Sat(); Serial.print("@"); break;
            case '+': Splus(); Serial.print("+"); break;
            //..
        }
        
        
    }
    Serial.println("");
    //space();
    delay(cycleInterval);

}
