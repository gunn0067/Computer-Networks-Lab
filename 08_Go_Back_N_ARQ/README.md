# Experiment 8 — Sliding Window Protocol (Go-Back-N ARQ)

**Aim:** Simulate the Go-Back-N automatic repeat request protocol.

**Compile:** `gcc go_back_n.c -o go_back_n`

**Run:** `./go_back_n`

Enter the number of frames and window size. Enter a cumulative ACK representing the next expected frame; enter -1 to simulate a lost ACK and timeout. This is a console simulation of the sender-side window behaviour.
