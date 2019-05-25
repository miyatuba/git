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
    //内部計算
    //表示
    this.draw.DrawBmp(this.soldier.getBmp(), 100, 20);
    this.draw.updateStageCreateJS();
};