const GOBLIN_IMAGE_DEFAULT_1_PATH = "resource/image/enemy/goblin_default.png";

class Goblin extends BaseEnemy {
    constructor() {
        super();
        this.bmp = new createjs.Bitmap(GOBLIN_IMAGE_DEFAULT_1_PATH);
        this.bmp.scaleX = 0.5;
        this.bmp.scaleY = 0.5;
    }

    getBmp() {
        return this.bmp;
    }

}


/*Goblin = function ()
{
    this.bmp = new createjs.Bitmap(GOBLIN_IMAGE_DEFAULT_1_PATH);
    this.bmp.scaleX = 0.5;
    this.bmp.scaleY = 0.5;
}

Goblin.bmp;

Goblin.prototype.getBmp = function ()
{
    return this.bmp;
}*/