
## Allowed signals: SIGUSR1, SIGUSR2

### Client: send a string to the server
- convert each character in the string into 8 bits
- send each bits using SIGUSR1 & SIGUSR2
- SIGUSR1 represents '0', SIGUSR2 represents '1'
- only continue sending bits after server finished processing the bit

### Server: receive bits sent from client and display it
- convert the signals into '1' & '0'
- for every 8 signals: print out the sum of (bit * 2^0~7)
- send SIGUSR1 back to the client to acknowledge message received
