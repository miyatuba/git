const SCENE_ID_BATTLE = 1;

SceneService = function ()
{
    //‚Æ‚è‚ ‚¦‚¸Å‰‚Íƒoƒgƒ‹ˆ—
    this.battle_scene = new BattleSence();
    this.current_scene = SCENE_ID_BATTLE;

}

SceneService.battle_scene;
SceneService.current_scene;

SceneService.prototype.play = function ()
{
    switch (current_scene) {
        case SCENE_ID_BATTLE:
            battle_scene.play();
            break;
    }
};