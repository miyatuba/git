class BaseEnemy
{
    constructor()
    {
        this.party_target_position_number = 1;
        this.enemy_target_position_number = 1;

        this.operation_rect_debug = new createjs.Shape();
        this.operation_rect_debug.graphics.setStrokeStyle(1);
        this.operation_rect_debug.graphics.beginStroke("blue");
        this.operation_rect_debug.graphics.drawRect(0, 0, 100, 120);

        this.operation_rect = new createjs.Shape();
        this.operation_rect.graphics.beginFill("black");
        this.operation_rect.graphics.drawRect(0, 0, 100, 120);
    }

    getOperationRect() {
        return this.operation_rect;

    }

    getOperationRectDebug() {
        return this.operation_rect_debug;

    }
}