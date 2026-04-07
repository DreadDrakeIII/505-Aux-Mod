# fef_chat

505th Expeditionary Force chat and comms module for Arma 3.

**Author:** Simba "Davy" Jones (RevGamer)

## Overview

`fef_chat` is the rebuilt 505th chat wheel backend module.
It handles squad comms, medical callouts, contact reports, reinsert requests, custom message pages, automessages, and voice-line hooks.

This version is focused on a **clean backend-first structure** before moving to a custom styled UI.

## Current Features

### Chat Wheel Menus
- Need Medic
- Need Ammo
- Contact
- Medic Check
- Medical Status
- More Page
- Reinsert submenu
- Custom message pages

### Contact Menu
- Infantry
- Vehicle
- Air

### Medical Status Menu
- Combat Ready
- Wounded
- Friendly Down

### Reinsert Menu
- x1 Reinsert
- x2 Reinsert
- x3 Reinsert
- x4 Reinsert
- x5 Reinsert

### Custom Messages
- 12 custom messages via CBA Addon Options
- split across 3 custom pages

### Automessages
- grenade throw callout
- smoke throw callout
- unconscious state callout

### Voice System
- local `say3D` voice playback hook
- language switching via addon option
- current populated audio assets:
  - `en_US` NeedMedic
  - `en_GB` NeedMedic

## Chat / Marker Rules

### Group Chat
Used for normal squad comms:
- Need Medic
- Need Ammo
- Contact reports
- Medic Check
- Medical Status responses
- Friendly Down text
- Custom messages

### Side Chat
Reserved for:
- Reinsert requests

### Friendly Down
Friendly Down currently does:
- group chat text
- same-side casualty marker

Tactical ping is intentionally postponed for now.

### Reinsert
Reinsert currently does:
- side chat request
- same-side reinsert marker

## Current Menu Layout

### Main Page
1. Need Medic
2. Need Ammo
3. Contact
4. Medic Check
5. Medical Status
6. More Page

### More Page
7. Reinsert
8. Custom
9. Back

### Contact
- Infantry
- Vehicle
- Air
- Back

### Medical Status
- Combat Ready
- Wounded
- Friendly Down
- Back

### Reinsert
- x1 Reinsert
- x2 Reinsert
- x3 Reinsert
- x4 Reinsert
- x5 Reinsert
- Back

### Custom
- Custom 01–12 across 3 pages

## Addon Options

### Voice
- enable / disable voice lines
- switch language profile

### Custom Messages
- 12 editable custom message slots

## Addon Controls
- Open Chat Wheel
- Quick Need Medic

## Voice Asset Status

Only the following audio folders are currently populated in this backend package:

- `Data/Audio/en_US/NeedMedic/`
- `Data/Audio/en_GB/NeedMedic/`

Other voice categories are scaffolded in config/code for future expansion, but will remain silent until matching `.ogg` files are added.

## Backend Notes

This module is currently considered the **backend-complete command-menu version**.

It is intended to provide:
- stable comms logic
- stable submenu flow
- stable marker behaviour
- stable CBA settings/keybind setup

before replacing the vanilla command menu with a custom 505th-styled UI.

## Planned Next Phase

### Custom UI
The next major development step is replacing the vanilla command menu with a custom styled interface.

Planned goals:
- better visuals
- proper colour styling
- improved layout
- cleaner submenu navigation
- 505th-themed presentation

### Voice Expansion
Voice support will be expanded later when the remaining `.ogg` files are available for:
- NeedAmmo
- EnemyContact
- MedicalCheck
- Throw
- Unconscious
- Reinsert if desired

## File Structure Notes

Key areas of the addon:

- `config.cpp` — registration and function setup
- `FEF_Sounds.hpp` — sound class definitions
- `Data/Functions/Chat/` — chat wheel logic
- `Data/Functions/EventHandlers/` — grenade/unconscious automation
- `Data/Functions/Settings/` — addon options and keybinds
- `Data/Functions/Sounds/` — voice playback and voice resolution
- `Data/Audio/` — voice assets

## Development Status

This version should be treated as the current stable backend checkpoint.

Focus from here should be:
1. backend cleanup and locking
2. custom UI replacement
3. later voice library expansion