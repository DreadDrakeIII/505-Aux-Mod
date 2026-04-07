params ["_bearing"];

switch (true) do {
    case (_bearing >= 337.5 || _bearing < 22.5): { "north" };
    case (_bearing < 67.5): { "north-east" };
    case (_bearing < 112.5): { "east" };
    case (_bearing < 157.5): { "south-east" };
    case (_bearing < 202.5): { "south" };
    case (_bearing < 247.5): { "south-west" };
    case (_bearing < 292.5): { "west" };
    default { "north-west" };
};
