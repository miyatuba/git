class BaseParty
{
    constructor(is_playable)
    {
        this.is_playable = is_playable;
        this.to_party_target_position_number = 1;
        this.to_enemy_target_position_number = 1;

        this.operation_rect_debug = new createjs.Shape();
        this.operation_rect_debug.graphics.setStrokeStyle(1);
        this.operation_rect_debug.graphics.beginStroke("blue");
        this.operation_rect_debug.graphics.drawRect(0, 0, 100, 160);

        this.operation_rect = new createjs.Shape();
        this.operation_rect.graphics.beginFill("black");
        this.operation_rect.graphics.drawRect(0, 0, 100, 160);
    }

    getOperationRect()
    {
        return this.operation_rect;
    
    }

    getOperationRectDebug()
    {
        return this.operation_rect_debug;

    }

    isPlayable()
    {
        return this.is_playable;
    }
    
    setToPartyTargetPositionNumber(position_number)
    {
        this.to_party_target_position_number = position_number;
    }

    setToEnemyTargetPositionNumber(position_number)
    {
        this.to_enemy_target_position_number = position_number;
    }

    getToPartyTargetPositionNumber()
    {
        return this.to_party_target_position_number;
    }

    getToEnemyTargetPositionNumber()
    {
        return this.to_party_target_position_number;
    }
}

