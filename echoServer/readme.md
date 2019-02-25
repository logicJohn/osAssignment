Compiled with javac

javac 10.0.2

Executed with java

openjdk version "10.0.2" 2018-07-17
OpenJDK Runtime Environment (build 10.0.2+13-Ubuntu-1ubuntu0.18.04.4)
OpenJDK 64-Bit Server VM (build 10.0.2+13-Ubuntu-1ubuntu0.18.04.4, mixed mode)

Compile:
javac Client.java
javac Server.java
Run:
java Server
java Client
Exit:
exits on input of ".exit"

client and server communicate over port 4000

---

The server opens communication on port 4000
THe client opens communication on port 4000

The server then waits for the client to send any data using the InputStream class. When the information is received the server prints the info then echos the info back to the client. This continues until the client exits with .exit
