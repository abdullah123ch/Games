#!/bin/bash

# === CONFIGURATION ===
APP_NAME="Pong Masters"
APP_ID="my-game"
SOURCE_DIR="$(pwd)"
BUILD_DIR="$SOURCE_DIR/build"
INSTALL_DIR="/opt/$APP_ID"
EXECUTABLE_NAME="game"         # Adjust based on your Makefile output
ICON_NAME="icon.png"
DESKTOP_FILE="$HOME/.local/share/applications/$APP_ID.desktop"

echo "🧱 Starting build and install process for $APP_NAME..."

# === Install build dependencies (if needed) ===
echo "🔧 Checking for build tools..."
sudo apt update
sudo apt install -y build-essential

# === Create build directory ===
mkdir -p "$BUILD_DIR"
cd "$SOURCE_DIR" || exit 1

# === Compile the game using Makefile ===
echo "⚙️ Building the game..."
make clean
make || { echo "❌ Build failed!"; exit 1; }

# === Create install dir ===
echo "📁 Installing to $INSTALL_DIR..."
sudo rm -rf "$INSTALL_DIR"
sudo mkdir -p "$INSTALL_DIR"

# === Move built binary and assets ===
sudo cp "$EXECUTABLE_NAME" "$INSTALL_DIR/"
[ -f "$ICON_NAME" ] && sudo cp "$ICON_NAME" "$INSTALL_DIR/"

# === Create .desktop launcher ===
echo "🖥️ Creating desktop shortcut..."
cat > "$DESKTOP_FILE" <<EOF
[Desktop Entry]
Name=$APP_NAME
Exec=$INSTALL_DIR/$EXECUTABLE_NAME
Icon=$INSTALL_DIR/$ICON_NAME
Type=Application
Categories=Game;
Terminal=false
EOF

chmod +x "$DESKTOP_FILE"

echo "✅ $APP_NAME installed successfully!"
echo "➡️ Launch it from the application menu or by typing: $APP_NAME"

