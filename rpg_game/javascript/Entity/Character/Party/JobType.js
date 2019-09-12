class JobType
{
    static SOLDIER_ID = 1;
    static LANCER_ID = 2;
    static ARCHER_ID = 3;
    static MAGE_ID = 4;
    static CLERIC_ID = 5;
    static ROOK_ID = 6;
    static BERSERK_ID = 7;
    static HUNTER_ID = 8;

    static getIdList()
    {
        return [
            JobType.SOLDIER_ID,
            JobType.LANCER_ID,
            JobType.ARCHER_ID,
            JobType.MAGE_ID,
            JobType.CLERIC_ID,
            JobType.ROOK_ID,
            JobType.BERSERK_ID,
            JobType.HUNTER_ID
        ];
    }

    static createInstanceForSoldier()
    {
        return new JobType(JobType.SOLDIER_ID);
    }

    static createInstanceForLancer()
    {
        return new JobType(JobType.LANCER_ID);
    }

    static createInstanceForArcher()
    {
        return new JobType(JobType.ARCHER_ID);
    }

    static createInstanceForMage()
    {
        return new JobType(JobType.MAGE_ID);
    }

    static createInstanceForCleric()
    {
        return new JobType(JobType.CLERIC_ID);
    }

    static createInstanceForRook()
    {
        return new JobType(JobType.ROOK_ID);
    }

    static createInstanceForBerserk()
    {
        return new JobType(JobType.BERSERK_ID);
    }

    static createInstanceForHunter()
    {
        return new JobType(JobType.HUNTER_ID);
    }

    constructor(type_id)
    {
        var id_list = JobType.getIdList();

        if (id_list.indexOf(type_id) == -1) {
            throw new Error('ê›íËÇ≥ÇÍÇƒÇ¢Ç»Ç¢idÇ™óàÇΩ');
        }

        this.id = type_id;
    }

    

}