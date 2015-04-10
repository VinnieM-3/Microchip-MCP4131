#include <SPI.h>
#include <MCP4131.h>

MCP4131 MCP4131(10); // with a CS pin of 10
int incomingByte = 0;

void setup(void)
{
  Serial.begin(9600);

  MCP4131.setTap(MCP4131_MIN); // Sets the pot to 0.

  if (MCP4131.initTCON())  // init the pot, connect wiper0, and turn ON pot
  {
    Serial.println("Init Error!");
  }

  Serial.println("SET TAP = 32");
  if (MCP4131.setTap(32))
  {
    Serial.println("setTap Error!");
  }
}

void loop(void)
{
  delay(5000);
  Serial.println("\nSTART LOOP");
  printout();

  delay(5000);
  Serial.println("\nDISCONNECT A");
  MCP4131.disconnectA();
  printout();

  delay(5000);
  Serial.println("\nCONNECT A");
  MCP4131.connectA();
  printout();

  delay(5000);
  Serial.println("\nDISCONNECT B");
  MCP4131.disconnectB();
  printout();

  delay(5000);
  Serial.println("\nCONNECT B");
  MCP4131.connectB();
  printout();

  delay(5000);
  Serial.println("\nDISCONNECT WIPER");
  MCP4131.disconnectWiper();
  printout();

  delay(5000);
  Serial.println("\nCONNECT WIPER");
  MCP4131.connectWiper();
  printout();

  delay(5000);
  Serial.println("\nSHUTDOWN");
  MCP4131.shutdownPot();
  printout();

  delay(5000);
  Serial.println("\nRESTART");
  MCP4131.startupPot();
  printout();
}

void printout() {
  Serial.print("isShutdown: ");
  Serial.println(MCP4131.isShutdown());
  Serial.print("isWiperConnected: ");
  Serial.println(MCP4131.isWiperConnected());
  Serial.print("isAConnected: ");
  Serial.println(MCP4131.isAConnected());
  Serial.print("isBConnected: ");
  Serial.println(MCP4131.isBConnected());
  Serial.print("WIPER: ");
  if (MCP4131.isShutdown()) {
    Serial.println("Wiper connected to B");
  } else if (!MCP4131.isWiperConnected()){
    Serial.println("Wiper Disconnected");    
  } else {
    Serial.println(MCP4131.Wiper_Reg, DEC);
  }
}
