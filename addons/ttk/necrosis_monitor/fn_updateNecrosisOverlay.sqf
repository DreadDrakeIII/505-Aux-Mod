/*
 * fn_updateNecrosisOverlay.sqf
 * [505th] Necrosis Monitor - Body Image Overlay Update
 *
 * Called every 0.5s by the medical menu PFH hook in XEH_postInit.
 * Reads OLI per-limb necrosis values and shows the appropriate stage
 * overlay on each of the four limb body image controls independently.
 *
 * Stages match KAT's own thresholds:
 *   0-20:   no overlay
 *   20-60:  stage 1
 *   60-90:  stage 2
 *   90-100: stage 3
 *
 * IDCs:
 *   72001/72002/72003 = left arm  stages 1/2/3
 *   72004/72005/72006 = right arm stages 1/2/3
 *   72007/72008/72009 = left leg  stages 1/2/3
 *   72010/72011/72012 = right leg stages 1/2/3
 */

private _display = uiNamespace getVariable ["ace_medical_gui_menuDisplay", displayNull];
if (isNull _display) exitWith {};

private _target = uiNamespace getVariable ["ace_medical_gui_target", objNull];
if (isNull _target) exitWith {};

private _leftArm  = _target getVariable ["OLI_necrosis_leftArm",  0];
private _rightArm = _target getVariable ["OLI_necrosis_rightArm", 0];
private _leftLeg  = _target getVariable ["OLI_necrosis_leftLeg",  0];
private _rightLeg = _target getVariable ["OLI_necrosis_rightLeg", 0];

// ─── Left arm ────────────────────────────────────────────────────────────────
(_display displayCtrl 72001) ctrlShow (_leftArm > 20 && _leftArm <= 60);
(_display displayCtrl 72002) ctrlShow (_leftArm > 60 && _leftArm <= 90);
(_display displayCtrl 72003) ctrlShow (_leftArm > 90);

// ─── Right arm ───────────────────────────────────────────────────────────────
(_display displayCtrl 72004) ctrlShow (_rightArm > 20 && _rightArm <= 60);
(_display displayCtrl 72005) ctrlShow (_rightArm > 60 && _rightArm <= 90);
(_display displayCtrl 72006) ctrlShow (_rightArm > 90);

// ─── Left leg ────────────────────────────────────────────────────────────────
(_display displayCtrl 72007) ctrlShow (_leftLeg > 20 && _leftLeg <= 60);
(_display displayCtrl 72008) ctrlShow (_leftLeg > 60 && _leftLeg <= 90);
(_display displayCtrl 72009) ctrlShow (_leftLeg > 90);

// ─── Right leg ───────────────────────────────────────────────────────────────
(_display displayCtrl 72010) ctrlShow (_rightLeg > 20 && _rightLeg <= 60);
(_display displayCtrl 72011) ctrlShow (_rightLeg > 60 && _rightLeg <= 90);
(_display displayCtrl 72012) ctrlShow (_rightLeg > 90);
