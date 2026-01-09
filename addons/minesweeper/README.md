# Minesweeper IED Module

A Zeus/Eden editor module that transforms objects into interactive minesweeper IED puzzles for Arma 3.

## Features

- **Interactive Minesweeper Game**: Classic minesweeper gameplay adapted for Arma 3 IED defusal scenarios
- **Zeus/Curator Compatible**: Place the module via Zeus for dynamic mission creation
- **Multiple Difficulty Levels**: Easy, Medium, and Hard presets that adjust mine count
- **Audio Feedback**: Beeping sounds and audio cues for player feedback
- **Realistic IED System**: Includes timer, mine counter, and proper defusal mechanics

## Installation

1. Place the `minesweeper` folder into your `addons` directory
2. Ensure proper HEMTT build configuration
3. Build with HEMTT: `hemtt build`

## Usage

### In Zeus/Curator
1. Open Zeus interface
2. Navigate to **Modules** → **Minesweeper IED Category**
3. Place **Minesweeper IED** module on an object
4. Configure difficulty (Easy/Medium/Hard)
5. Players can interact with the object to start defusal

### In Eden Editor
1. Place the **MSW_ModuleMinesweeperIED** module
2. Sync it to the desired object
3. Set difficulty in module attributes
4. Preview/play mission

## Configuration

### Difficulty Settings
- **Easy**: Lower mine count, easier to solve
- **Medium**: Moderate mine count (default)
- **Hard**: Higher mine count, more challenging

Mine counts are configured in `IED\init_minefield.sqf`

## File Structure

```
minesweeper/
├── $PBOPREFIX$                 # PBO prefix definition
├── config.cpp                   # Main configuration
├── script_component.hpp         # HEMTT component setup
├── CfgFactionClasses.hpp       # Module category definition
├── CfgFunctions.hpp            # Function registration
├── CfgVehicles.hpp             # Module definition
├── functions/                   # SQF functions
│   ├── fn_moduleApplyIED.sqf   # Module application function
│   ├── fn_initShoterIED.sqf    # IED initialization (preInit)
│   ├── fn_Minesweeper.sqf      # Main minesweeper function
│   └── script_component.hpp    # Component include
├── IED/                         # Core minesweeper system
│   ├── init.sqf                # Main initialization
│   ├── init_ied.sqf            # IED setup
│   ├── init_minefield.sqf      # Minefield generation
│   ├── sweeper_tick.sqf        # Timer tick function
│   ├── ied_tick.sqf            # IED update function
│   ├── tileClick.sqf           # Tile interaction handler
│   ├── uncover.sqf             # Tile reveal logic
│   ├── getField.sqf            # Field state retrieval
│   ├── bombCount.sqf           # Adjacent mine counter
│   ├── complete.sqf            # Success handler
│   ├── detonate.sqf            # Failure/explosion handler
│   ├── ied_damage.sqf          # Damage handling
│   ├── safeStart.sqf           # Safe start logic
│   ├── defines.def             # Path definitions
│   ├── defines.hpp             # UI control definitions
│   ├── minesweeper.hpp         # Dialog configuration
│   └── img/                     # UI images
│       ├── tile.paa            # Unrevealed tile
│       ├── tileFlag.paa        # Flagged tile
│       ├── empty.paa           # Empty revealed tile
│       ├── mine.paa            # Mine icon
│       ├── clock.paa           # Timer icon
│       └── 1.paa - 8.paa       # Number tiles
└── sounds/                      # Audio files
    ├── standard_beep.ogg       # Beeping sound
    ├── start_defusing.ogg      # Start sound
    ├── success.ogg             # Success sound
    └── failure.ogg             # Failure/explosion sound
```

## Functions

### MSW_fnc_moduleApplyIED
Applies the minesweeper IED module to a synced object.

### MSW_fnc_initShoterIED
PreInit function that initializes the IED system.

### MSW_fnc_Minesweeper
Main function to create a minesweeper IED on an object.

**Parameters:**
- `_ied`: Object to convert into IED
- `_mineCount`: Number of mines (or difficulty string)
- `_timer`: Timer duration in seconds
- `_explosionType`: Explosion classname
- `_side`: Side that can interact with IED
- `_audibleBeforeDefusal`: Whether IED beeps before interaction

## Requirements

- Arma 3
- CBA_A3 (recommended)
- EHB Main addon (for proper HEMTT integration)

## Credits

- **Original Author**: z
- **HEMTT Conversion**: RevGamer
- **EHB Accessibility Mod**: RevGamer & Team

## License

See main mod LICENSE for details.

## Changelog

### v1.1.0 (HEMTT Conversion)
- Converted to proper HEMTT structure
- Updated all paths to use HEMTT macros
- Split config into modular components
- Added proper documentation
- Updated PBO prefix to `z\ehb\addons\minesweeper`

### v1.0.0 (Original)
- Initial release by z
- Core minesweeper functionality
- Zeus/Curator integration
