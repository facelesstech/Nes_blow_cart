#include <rtttl.h>

int threshold = 30;  // Sound sensor threshold - lower for more sensative higher for less
int volume;  // Readings from sound sensor
int pinSpeaker = 1;  // Speaker pin 1
const int octave = 0;  // The octave set for the player

int song_picker;  // Where the random song picker number is stored

//  --------------------- TFFFI Songs --------------------- 
const char song_1[] PROGMEM =
"smwwd1:d=4,o=5,b=125:a,8f.,16c,16d,16f,16p,f,16d,16c,16p,16f,16p,16f,16p,8c6,8a.,g";
const char song_2[] PROGMEM =
"smbdeath:d=4,o=5,b=100:32c6,16b,16f6,16p,16f6,16f.6,16e.6,16d6,16c6,16p,16e,16p,16c";
const char song_3[] PROGMEM =
"smw_title:d=4,o=5,b=125:8d7,8d7,8d7,8d6,8d7,8d7,8d7,8d6,2d#7,8d7,p,32p,8d6,8b6,8b6,8b6,8d6,8b6,8b6,8b6,8d6,8b6,8b6,8b6,16b6,16c7,b6,8a6";
const char song_4[] PROGMEM =
"smw_clear:d=4,o=5,b=80:8g6,8g6,16e6,8g6,16e6,16g6,16e6,16d6,8g.6,16p,32d6,16d7,16e7,16d7,16e7,16d.7,32d6,32c7,32b6,16a6,8g.6,16p,8g7";
const char song_5[] PROGMEM =
"smb_under:d=4,o=6,b=100:32c,32p,32c7,32p,32a5,32p,32a,32p,32a#5,32p,32a#,2p,32c,32p,32c7,32p,32a5,32p,32a,32p,32a#5,32p,32a#,2p,32f5,32p,32f,32p,32d5,32p,32d,32p,32d#5,32p,32d#";//,2p,32f5,32p,32f,32p,32d5,32p,32d,32p,32d#5,32p,32d#";
const char song_6[] PROGMEM =
"zelda_storms:d=4,o=5,b=180:8d6,8f6,d7,p,8d6,8f6,d7,p,e7,8p,8f7,8e7,8f7,8e7,8c7,a6";
const char song_7[] PROGMEM =
"smb:d=4,o=5,b=100:16e6,16e6,32p,8e6,16c6,8e6,8g6,8p,8g,8p,8c6,16p,8g,16p,8e,16p,8a,8b,16a#,8a,16g.,16e6,16g6,8a6,16f6,8g6,8e6,16c6,16d6,8b";
const char song_8[] PROGMEM =
"ocarina:d=4,o=5,b=100:b,16p,8d6,32p,a,16p,16g,32p,16a,32p,b,16p,8d6,32p,2a,16p,b,16p,8d6,32p,a6,16p,8g6,32p,d6,16p,16c6,32p,16b,32p,2a"; 
const char song_9[] PROGMEM =
"PacMan:d=16,o=6,b=140:b5,b,f#,d#,8b,8d#,c,c7,g,f,8c7,8e,b5,b,f#,d#,8b,8d#,32d#,32e,f,32f,32f#,g,32g,32g#,a,8b";
const char song_10[] PROGMEM =
"korobyeyniki:d=4,o=5,b=160:e6,8b,8c6,8d6,16e6,16d6,8c6,8b,a,8a,8c6,e6,8d6,8c6,b,8b,8c6,d6,e6,c6,a,2a";
const char song_11[] PROGMEM =
"exbike:d=4,o=5,b=112:8e,8g,8c6,16e,8g,4c.6,16p,8g#,8b,8e6,16g#,8b,4e.6,16p,16d.6,32c6,16d.6,32c6,16a.,32g,8f,16f.,32e,16d#.,8d.,16c,8e,8f,8f#,16g,4c6";
const char song_12[] PROGMEM =
"Zelda1:d=4,o=5,b=125:a#,f.,8a#,16a#,16c6,16d6,16d#6,2f6,8p,8f6,16f.6,16f#6,16g#.6,2a#.6,16a#.6,16g#6,16f#.6,8g#.6,16f#.6,2f6";
const char song_13[] PROGMEM =
"ZeldaDung:d=4,o=5,b=80:16g,16a#,16d6,16d#6,16g,16a#,16d6,16d#6,16g,16a#,16d6,16d#6,16g,16a#,16d6,16d#6,16f#,16a,16d6,16d#6,16f#,16a,16d6,16d#6,16f#,16a,16d6,16d#6,16f#,16a,16d6,16d#6";


Rtttl player;  // Song player

void setup() {
  player.begin(pinSpeaker);  // Starts the player
  pinMode(pinSpeaker, OUTPUT);  // Speaker set as output
  randomSeed(666);  // Random seed of the random picker
}

void playSong(const char * track)  // Takes the song_# pasted from the if statements below
{
  player.play_P(track, octave);  // Passes the song_# and octave to the player
}

void loop() {
  volume = analogRead(A1); // Reads the value from the Analog PIN A0

  if(volume<=threshold){  // If the volume reading exceeds the threshold it will pick a random number from 1 - 14
    song_picker = random(14);

    if (song_picker == 1) {  // If the random number matches this one it will play this tune in the TFFFI player
      playSong(song_1);
    }

    if (song_picker == 2) {  // If the random number matches this one it will play this tune in the TFFFI player
      playSong(song_2);
    }

    if (song_picker == 3) {  // If the random number matches this one it will play this tune in the TFFFI player
      playSong(song_3);
    }

    if (song_picker == 4) {  // If the random number matches this one it will play this tune in the TFFFI player
      playSong(song_4);
    }

    if (song_picker == 5) {  // If the random number matches this one it will play this tune in the TFFFI player
      playSong(song_5);
    }

    if (song_picker == 6) {  // If the random number matches this one it will play this tune in the TFFFI player
      playSong(song_6);
    }

    if (song_picker == 7) {  // If the random number matches this one it will play this tune in the TFFFI player
      playSong(song_7);
    }

    if (song_picker == 8) {  // If the random number matches this one it will play this tune in the TFFFI player
      playSong(song_8);
    }
    
    if (song_picker == 9) {  // If the random number matches this one it will play this tune in the TFFFI player
      playSong(song_9);
    }
    
    if (song_picker == 10) {  // If the random number matches this one it will play this tune in the TFFFI player
      playSong(song_10);
    }
    
    if (song_picker == 11) {  // If the random number matches this one it will play this tune in the TFFFI player
      playSong(song_11);
    }
    
    if (song_picker == 12) {  // If the random number matches this one it will play this tune in the TFFFI player
      playSong(song_12);
    }
    
    if (song_picker == 13) {  // If the random number matches this one it will play this tune in the TFFFI player
      playSong(song_13);
    }
  }
}

