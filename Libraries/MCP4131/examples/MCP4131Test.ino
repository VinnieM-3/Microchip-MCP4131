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

  Serial.println("\n\n\n\nSET TAP");
  if (MCP4131.setTap(32))
  {
    Serial.println("setTap Error!");
  }
}

void loop(void)
{
  if (MCP4131.readTCON() == false)
  {
    delay(5000);
    Serial.println("\nSTART LOOP");
    Serial.print("isShutdown:");
    Serial.println(MCP4131.isShutdown());
    Serial.print("isWiperConnected:");
    Serial.println(MCP4131.isWiperConnected());
    Serial.print("isAConnected:");
    Serial.println(MCP4131.isAConnected());
    Serial.print("isBConnected:");
    Serial.println(MCP4131.isBConnected());
    Serial.print("WIPER:");
    Serial.println(MCP4131.Wiper_Reg, DEC);

    delay(5000);
    Serial.println("\nDISCONNECT A");
    MCP4131.disconnectA();
    Serial.print("isShutdown:");
    Serial.println(MCP4131.isShutdown());
    Serial.print("isWiperConnected:");
    Serial.println(MCP4131.isWiperConnected());
    Serial.print("isAConnected:");
    Serial.println(MCP4131.isAConnected());
    Serial.print("isBConnected:");
    Serial.println(MCP4131.isBConnected());
    Serial.print("WIPER:");
    Serial.println(MCP4131.Wiper_Reg, DEC);

    delay(5000);
    Serial.println("\nCONNECT A");
    MCP4131.connectA();
    Serial.print("isShutdown:");
    Serial.println(MCP4131.isShutdown());
    Serial.print("isWiperConnected:");
    Serial.println(MCP4131.isWiperConnected());
    Serial.print("isAConnected:");
    Serial.println(MCP4131.isAConnected());
    Serial.print("isBConnected:");
    Serial.println(MCP4131.isBConnected());
    Serial.print("WIPER:");
    Serial.println(MCP4131.Wiper_Reg, DEC);

    delay(5000);
    Serial.println("\nDISCONNECT B");
    MCP4131.disconnectB();
    Serial.print("isShutdown:");
    Serial.println(MCP4131.isShutdown());
    Serial.print("isWiperConnected:");
    Serial.println(MCP4131.isWiperConnected());
    Serial.print("isAConnected:");
    Serial.println(MCP4131.isAConnected());
    Serial.print("isBConnected:");
    Serial.println(MCP4131.isBConnected());
    Serial.print("WIPER:");
    Serial.println(MCP4131.Wiper_Reg, DEC);

    delay(5000);
    Serial.println("\nCONNECT B");
    MCP4131.connectB();
    Serial.print("isShutdown:");
    Serial.println(MCP4131.isShutdown());
    Serial.print("isWiperConnected:");
    Serial.println(MCP4131.isWiperConnected());
    Serial.print("isAConnected:");
    Serial.println(MCP4131.isAConnected());
    Serial.print("isBConnected:");
    Serial.println(MCP4131.isBConnected());
    Serial.print("WIPER:");
    Serial.println(MCP4131.Wiper_Reg, DEC);

    delay(5000);
    Serial.println("\nDISCONNECT WIPER");
    MCP4131.disconnectWiper();
    Serial.print("isShutdown:");
    Serial.println(MCP4131.isShutdown());
    Serial.print("isWiperConnected:");
    Serial.println(MCP4131.isWiperConnected());
    Serial.print("isAConnected:");
    Serial.println(MCP4131.isAConnected());
    Serial.print("isBConnected:");
    Serial.println(MCP4131.isBConnected());
    Serial.print("WIPER:");
    Serial.println(MCP4131.Wiper_Reg, DEC);

    delay(5000);
    Serial.println("\nCONNECT WIPER");
    MCP4131.connectWiper();
    Serial.print("isShutdown:");
    Serial.println(MCP4131.isShutdown());
    Serial.print("isWiperConnected:");
    Serial.println(MCP4131.isWiperConnected());
    Serial.print("isAConnected:");
    Serial.println(MCP4131.isAConnected());
    Serial.print("isBConnected:");
    Serial.println(MCP4131.isBConnected());
    Serial.print("WIPER:");
    Serial.println(MCP4131.Wiper_Reg, DEC);

    delay(5000);
    Serial.println("\nSHUTDOWN");
    MCP4131.shutdownPot();
    Serial.print("isShutdown:");
    Serial.println(MCP4131.isShutdown());
    Serial.print("isWiperConnected:");
    Serial.println(MCP4131.isWiperConnected());
    Serial.print("isAConnected:");
    Serial.println(MCP4131.isAConnected());
    Serial.print("isBConnected:");
    Serial.println(MCP4131.isBConnected());
    Serial.print("WIPER:");
    Serial.println(MCP4131.Wiper_Reg, DEC);

    delay(5000);
    Serial.println("\nRESTART");
    MCP4131.startupPot();
    Serial.print("isShutdown:");
    Serial.println(MCP4131.isShutdown());
    Serial.print("isWiperConnected:");
    Serial.println(MCP4131.isWiperConnected());
    Serial.print("isAConnected:");
    Serial.println(MCP4131.isAConnected());
    Serial.print("isBConnected:");
    Serial.println(MCP4131.isBConnected());
    Serial.print("WIPER:");
    Serial.println(MCP4131.Wiper_Reg, DEC);
  }
}
