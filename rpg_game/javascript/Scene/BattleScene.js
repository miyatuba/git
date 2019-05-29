const BATTLE_BACK_GRAUND_IMAGE = "resource/image/back_graund/back_ground1.jpg";
BattleScene = function ()
{
    this.draw = new Draw();

    this.soldier = new Soldier;
    this.lancer = new Lancer;
    this.archer = new Archer;
    this.mage = new Mage;
    this.cleric = new Cleric;
    this.rook = new Rook;
    this.berserk = new Berserk;
    this.hunter = new Hunter;

    this.enemy1 = new Goblin;
    this.enemy2 = new Goblin;
    this.enemy3 = new Goblin;
    this.enemy4 = new Goblin;
    this.enemy5 = new Goblin;
    this.enemy6 = new Goblin;

    bmp_back_ground = new createjs.Bitmap(BATTLE_BACK_GRAUND_IMAGE);
    bmp_back_ground.scaleX = 1;
    bmp_back_ground.scaleY = 1;
    this.draw.DrawBmp(bmp_back_ground, 0, 0);
    this.draw.DrawBmp(this.soldier.getBmp(), 450, 20);
    this.draw.DrawBmp(this.lancer.getBmp(), 450, 170);
    this.draw.DrawBmp(this.archer.getBmp(), 570, 70);
    this.draw.DrawBmp(this.mage.getBmp(), 570, 220);
    this.draw.DrawBmp(this.cleric.getBmp(), 700, 20);
    this.draw.DrawBmp(this.cleric.getRectCollision(), 700, 20);

    this.draw.DrawBmp(this.rook.getBmp(), 700, 170);
    this.draw.DrawBmp(this.berserk.getBmp(), 820, 70);
    this.draw.DrawBmp(this.hunter.getBmp(), 820, 220);
    this.draw.DrawBmp(this.enemy1.getBmp(), 200, 70);
    this.draw.DrawBmp(this.enemy2.getBmp(), 200, 220);
    this.draw.DrawBmp(this.enemy3.getBmp(), 100, 20);
    this.draw.DrawBmp(this.enemy4.getBmp(), 100, 170);
    this.draw.DrawBmp(this.enemy5.getBmp(), 0, 70);
    this.draw.DrawBmp(this.enemy6.getBmp(), 0, 220);
}

BattleScene.draw;

BattleScene.soldier;
BattleScene.lancer;
BattleScene.archer;
BattleScene.mage;
BattleScene.cleric;
BattleScene.rook;
BattleScene.berserk;
BattleScene.hunter;

BattleScene.prototype.play = function ()
{
    //入力処理
    var clericRectCollision = this.cleric.getRectCollision();
    clericRectCollision.addEventListener("click", handleTest);
    function handleTest() {
        alert("クレリックが選択されました");
    }

    //内部計算
    //表示

    this.draw.updateStageCreateJS();
};