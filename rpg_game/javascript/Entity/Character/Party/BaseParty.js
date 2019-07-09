class BaseParty
{
    constructor(is_playable)
    {
        this.is_playable = is_playable;
        this.to_party_target_position_number = 1;
        this.to_enemy_target_position_number = 1;
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

