// OLI_KCS - non-null, alive tracked patients of a computer.
//
// Arguments: 0: computer <OBJECT>
// Returns: patients <ARRAY>

params ["_computer"];

(_computer getVariable ["OLI_KCS_ActivePatients", []]) select {!isNull _x && {alive _x}}
