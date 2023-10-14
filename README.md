# TravelingTrader Mod for DayZ

Welcome to the **TravelingTrader** mod repository, crafted by **LinuxPhantom**. This mod introduces dynamic traders that rotate between predefined positions in your DayZ server, offering an engaging and unpredictable experience for players.

## How It Works

1. **Configuration File**: The mod uses a `config.json` file that's included in the `INFO` folder inside the mod. This file defines:
   - A unique ID for each trader.
   - The interval (in milliseconds) after which the trader will change their position.
   - A message displayed to players when the trader moves.
   - A list of possible positions for the trader.
   - The orientation the trader will face at each position.

2. **Server Profiles**: The mod generates a directory in the server profiles. Server owners should copy the `config.json` from the `INFO` folder and paste it into this generated directory to ensure smooth operation.

## Configuration Guide

### `MoveTime`

- Represents the time interval after which the trader will change their position.
- Example: If set to `1800000`, the trader will move every 30 minutes.

### `Position` (Coordinates)

- Defines the possible positions the trader can occupy.
- Example: `"3699.27 402.13 5967.91"` is a coordinate set for Green Mountain.

### `Orientation`

- Determines the direction the trader will face at a particular position.
- Example: `"-13.234265 0 0"` sets the trader's orientation at Green Mountain.

## Sample Configuration

Below is an example `config.json`:

```json
{
    "RTTraderData": [
        {
            "ID": 0,
            "MoveTime": 1800000,
            "MoveMessage": "The Trader Has Moved",
            "Position": [
                "3699.27 402.13 5967.91",
                "8354.06 293.143 5995.87"
            ],
            "Orientation": [
                "-13.234265 0 0",
                "0 0 0"
            ]
        },
        {
            "ID": 1,
            "MoveTime": 1800000,
            "MoveMessage": "The Trader Has Moved",
            "Position": [
                "3691.41 402.074 5998.47",
                "8357.55 293.143 5995.26"
            ],
            "Orientation": [
                "158.253525 0 0",
                "-169.334961 0 0"
            ]
        }
    ]
}
```

## Join Our Discord

For more details, support, or to engage with our community, join our Discord server: [https://discord.com/invite/TcvUsbjagA](https://discord.com/invite/TcvUsbjagA).

## License & Rights

This mod is the property of **LinuxPhantom**. Unauthorized distribution, modification, or repackaging is strictly prohibited and will result in severe actions.

---

Crafted with :heart: by [LinuxPhantom](https://github.com/LinuxPhantom/Traveling-Trader).

