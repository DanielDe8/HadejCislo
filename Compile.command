SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
g++ $SCRIPT_DIR/index.cpp -o $SCRIPT_DIR/Output
g++ $SCRIPT_DIR/index.cpp -o $SCRIPT_DIR/Output.exe
sleep 5000000