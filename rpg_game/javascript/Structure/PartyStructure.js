
class PartyStructure
{
	constructor()
    {

    }

	//���͒�����
    getPartyForBattlePosition1()
    {
        return new Soldier(false);
    }

    getPartyForBattlePosition2()
    {
        return new Lancer(false);
    }

    getPartyForBattlePosition3()
    {
        return new Archer(false);
    }

    getPartyForBattlePosition4()
    {
        return new Mage(false);
    }

    getPartyForBattlePosition5()
    {
        return new Cleric(false);
    }

    getPartyForBattlePosition6()
    {
        return new Rook(false);
    }

    getPartyForBattlePosition7()
    {
        return new Berserk(true);//��肭�ϓ�����悤�ɕύX����
    }

    getPartyForBattlePosition8()
    {
        return new Hunter(false);
    }

    getPlayablePartyPositionNumber()
    {
        return 7;
    }
}