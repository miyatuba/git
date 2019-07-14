//レイヤーメモ
//create.jsでは、透明とかにすると、操作判定まで消えてしまう。操作判定がない画像で上書きする分には判定が消えないために、以下のように対応する必要がある
//当たり判定レイヤーを先に描画→背景描画→キャラやエフェクトなどの描画。

class Draw
{
    constructor()
    {
        this.stageCreateJS = new createjs.Stage("maincanvas0");
    }

    DrawBmp(bmp, x, y)
    {
        bmp.x = x;
        bmp.y = y;
        this.stageCreateJS.addChild(bmp);
    }

    updateStageCreateJS()
    {
        this.stageCreateJS.update();
    }
}

