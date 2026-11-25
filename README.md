# Computer Networks Laboratory Practicals

A collection of Computer Networks laboratory experiments covering networking fundamentals, file sharing, TCP/UDP socket programming, DNS and HTTP analysis, Go-Back-N ARQ, traffic shaping, and routing.

## Experiments

| Experiment | Topic | Main files |
|---|---|---|
| 1A | Fundamental Elements of Computer Networking | README.md |
| 1B | File Sharing Within an Organization | commands.txt, README.md |
| 2 | TCP Server | tcp_server.c |
| 3 | TCP Client | tcp_client.c |
| 4 | UDP Server | udp_server.c |
| 5 | UDP Client | udp_client.c |
| 6 | DNS Analysis Using Wireshark | commands.txt, output.txt |
| 7 | Application Layer Packet Analysis | commands.txt, output.txt |
| 8 | Sliding Window Protocol (Go-Back-N) | go_back_n.c |
| 9A | Leaky Bucket Algorithm | leaky_bucket.c |
| 9B | Token Bucket Algorithm | token_bucket.c |
| 10 | Distance Vector Routing | distance_vector.c |

## Requirements
- GCC compiler
- Wireshark for Experiments 6 and 7
- Linux or WSL for POSIX socket programs

## Compile and run
Run commands from the relevant experiment directory.

```bash
gcc tcp_server.c -o tcp_server
./tcp_server
```

For socket experiments, start the server in one terminal and the client in another. Compile the remaining programs similarly, using the source filename as the output name.

## Wireshark filters
- `dns` — DNS packets
- `http` — HTTP packets where unencrypted HTTP is present
- `tcp` — TCP packets
- `udp` — UDP packets

Actual command output and packet captures depend on your operating system and network.
