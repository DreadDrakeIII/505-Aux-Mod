
_ied = _this select 0;
_X = _this select 1;
_Y = _this select 2;
_count = 0;
if ( not((_ied getVariable "ShoterIed_Value" + format ["%1%2", _X, _Y]) isEqualTo "B")) then
{
	if(_X != 1) then
	{
		if ( (_ied getVariable "ShoterIed_Value" + format ["%1%2", _X - 1, _Y]) isEqualTo "B") then
		{
		_count = _count + 1;
		};
	};

	if(_Y != 1) then
	{
		if ( (_ied getVariable "ShoterIed_Value" + format ["%1%2", _X , _Y - 1]) isEqualTo "B") then
		{
		_count = _count + 1;
		};
	};

	if(_X != 9) then
	{
		if ( (_ied getVariable "ShoterIed_Value" + format ["%1%2", _X + 1, _Y]) isEqualTo "B") then
		{
		_count = _count + 1;
		};
	};

	if(_Y != 9) then
	{
		if ( (_ied getVariable "ShoterIed_Value" + format ["%1%2", _X , _Y + 1]) isEqualTo "B") then
		{
		_count = _count + 1;
		};
	};

	if(_X != 1 AND _Y != 1) then
	{
		if ( (_ied getVariable "ShoterIed_Value" + format ["%1%2", _X - 1 , _Y - 1]) isEqualTo "B") then
		{
		_count = _count + 1;
		};
	};

	if(_X != 1 AND _Y != 9) then
	{
		if ( (_ied getVariable "ShoterIed_Value" + format ["%1%2", _X - 1 , _Y + 1]) isEqualTo "B") then
		{
		_count = _count + 1;
		};
	};

	if(_X != 9 AND _Y != 1) then
	{
		if ( (_ied getVariable "ShoterIed_Value" + format ["%1%2", _X + 1 , _Y - 1]) isEqualTo "B") then
		{
		_count = _count + 1;
		};
	};

	if(_X != 9 AND _Y != 9) then
	{
		if ( (_ied getVariable "ShoterIed_Value" + format ["%1%2", _X + 1 , _Y + 1]) isEqualTo "B") then
		{
		_count = _count + 1;
		};
	};
};
_count
