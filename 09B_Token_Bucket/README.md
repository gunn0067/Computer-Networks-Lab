# Experiment 9B — Token Bucket Algorithm

Aim: Simulate traffic control using the Token Bucket algorithm.

Compile: `gcc token_bucket.c -o token_bucket`
Run: `./token_bucket`

A packet is transmitted when enough tokens are available. Tokens are consumed according to packet cost and replenished at the configured rate, up to bucket capacity.