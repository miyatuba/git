const SCENE_ID_BATTLE = 1;

class SceneService
{
    constructor()
    {
        this.battle_scene = new BattleScene();
        this.current_scene = SCENE_ID_BATTLE;
    }

    play()
    {
        switch (this.current_scene) {
            case SCENE_ID_BATTLE:
                this.battle_scene.play();
                break;
        }
    }
}


/*SceneService = function ()
{
    //Ç∆ÇËÇ†Ç¶Ç∏ç≈èâÇÕÉoÉgÉãèàóù
    this.battle_scene = new BattleScene();
    this.current_scene = SCENE_ID_BATTLE;

}

SceneService.battle_scene;
SceneService.current_scene;

SceneService.prototype.play = function ()
{
    switch (this.current_scene) {
        case SCENE_ID_BATTLE:
            this.battle_scene.play();
            break;
    }
};*/