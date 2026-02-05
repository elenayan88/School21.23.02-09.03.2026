#!/bin/bash

cd ai_help
chmod +x unifier.sh
chmod +x keygen.sh
sh keygen.sh
find ./key/* -type f ! -name "*.key" -delete
sh unifier.sh
