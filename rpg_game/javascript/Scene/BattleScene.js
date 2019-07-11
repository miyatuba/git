class BattleScene {
    BATTLE_BACK_GRAUND_IMAGE = "resource/image/back_graund/back_ground1.jpg";

    PLAYER_CURSOR_1_PATH = "resource/image/battle/player_cursor1.png";
    ENEMY_CURSOR_1_PATH = "resource/image/battle/enemy_cursor1.png";

    PARTY_NUMBER_ID_SOLDIER = 1;
    PARTY_NUMBER_ID_LANCER = 2;
    PARTY_NUMBER_ID_ARCHER = 3;
    PARTY_NUMBER_ID_MAGE = 4;
    PARTY_NUMBER_ID_CLERIC = 5;
    PARTY_NUMBER_ID_ROOK = 6;
    PARTY_NUMBER_ID_BERSERK = 7;
    PARTY_NUMBER_ID_HUNTER = 8;
    

    PARTY_CHARACTER1_POSITION_X = 480;
    PARTY_CHARACTER1_POSITION_Y = 20;
    PARTY_CHARACTER2_POSITION_X = 450;
    PARTY_CHARACTER2_POSITION_Y = 170;
    PARTY_CHARACTER3_POSITION_X = 570;
    PARTY_CHARACTER3_POSITION_Y = 70;
    PARTY_CHARACTER4_POSITION_X = 570;
    PARTY_CHARACTER4_POSITION_Y = 220;
    PARTY_CHARACTER5_POSITION_X = 700;
    PARTY_CHARACTER5_POSITION_Y = 20;
    PARTY_CHARACTER6_POSITION_X = 700;
    PARTY_CHARACTER6_POSITION_Y = 170;
    PARTY_CHARACTER7_POSITION_X = 820;
    PARTY_CHARACTER7_POSITION_Y = 70;
    PARTY_CHARACTER8_POSITION_X = 820;
    PARTY_CHARACTER8_POSITION_Y = 220;
    PLAYER_CURSOR_RELATIVE_POSITION_X = 100;
    PLAYER_CURSOR_RELATIVE_POSITION_Y = 150;
    
    constructor(partyStructure)
    {
        this.party_structure = partyStructure;

        this.battle_input = new BattleInput();

        this.draw = new Draw();
        
        

        this._initPartyDeploy();
        this._initEnemyDeploy();
        this._initDraw();

        /*// 四角形の作成
        var rect = new createjs.Shape();
        rect.graphics.beginFill("green").drawRect(200, 20, 160, 160);
        this.draw.DrawBmp(rect);
        // 各種マウスイベントを登録する
        rect.addEventListener("click", handleRectClick);
        // クリックしたとき
        function handleRectClick(event) {
            alert("四がクリックされました");
        }
        this.draw.updateStageCreateJS();*/
        
        // 四角形の作成
        var rect = new createjs.Shape();
        rect.graphics.beginFill("red").drawRect(200, 20, 160, 160);
        this.draw.DrawBmp(rect, 0, 0);
        
        this.battle_input.setTest(rect);

    }

    _initDraw()
    {
        var bmp_back_ground = new createjs.Bitmap(this.BATTLE_BACK_GRAUND_IMAGE);
        bmp_back_ground.scaleX = 1;
        bmp_back_ground.scaleY = 1;
        this.draw.DrawBmp(bmp_back_ground, 0, 0);
        this.draw.DrawBmp(this.party_character1.getBmp(), this.PARTY_CHARACTER1_POSITION_X, this.PARTY_CHARACTER1_POSITION_Y);
        this.draw.DrawBmp(this.party_character1.getRectCollision(), this.PARTY_CHARACTER1_POSITION_X, this.PARTY_CHARACTER1_POSITION_Y);
        this.draw.DrawBmp(this.party_character2.getBmp(), this.PARTY_CHARACTER2_POSITION_X, this.PARTY_CHARACTER2_POSITION_Y);
        this.draw.DrawBmp(this.party_character2.getRectCollision(), this.PARTY_CHARACTER2_POSITION_X, this.PARTY_CHARACTER2_POSITION_Y);
        this.draw.DrawBmp(this.party_character3.getBmp(), this.PARTY_CHARACTER3_POSITION_X, this.PARTY_CHARACTER3_POSITION_Y);
        this.draw.DrawBmp(this.party_character3.getRectCollision(), this.PARTY_CHARACTER3_POSITION_X, this.PARTY_CHARACTER3_POSITION_Y);
        this.draw.DrawBmp(this.party_character4.getBmp(), this.PARTY_CHARACTER4_POSITION_X, this.PARTY_CHARACTER4_POSITION_Y);
        this.draw.DrawBmp(this.party_character4.getRectCollision(), this.PARTY_CHARACTER4_POSITION_X, this.PARTY_CHARACTER4_POSITION_Y);
        this.draw.DrawBmp(this.party_character5.getBmp(), this.PARTY_CHARACTER5_POSITION_X, this.PARTY_CHARACTER5_POSITION_Y);
        this.draw.DrawBmp(this.party_character5.getRectCollision(), this.PARTY_CHARACTER5_POSITION_X, this.PARTY_CHARACTER5_POSITION_Y);
        this.draw.DrawBmp(this.party_character6.getBmp(), this.PARTY_CHARACTER6_POSITION_X, this.PARTY_CHARACTER6_POSITION_Y);
        this.draw.DrawBmp(this.party_character6.getRectCollision(), this.PARTY_CHARACTER6_POSITION_X, this.PARTY_CHARACTER6_POSITION_Y);
        this.draw.DrawBmp(this.party_character7.getBmp(), this.PARTY_CHARACTER7_POSITION_X, this.PARTY_CHARACTER7_POSITION_Y);
        this.draw.DrawBmp(this.party_character7.getRectCollision(), this.PARTY_CHARACTER7_POSITION_X, this.PARTY_CHARACTER7_POSITION_Y);
        this.draw.DrawBmp(this.party_character8.getBmp(), this.PARTY_CHARACTER8_POSITION_X, this.PARTY_CHARACTER8_POSITION_Y);
        this.draw.DrawBmp(this.party_character8.getRectCollision(), this.PARTY_CHARACTER8_POSITION_X, this.PARTY_CHARACTER8_POSITION_Y);
        this.draw.DrawBmp(this.enemy_character_position1.getBmp(), 200, 70);
        this.draw.DrawBmp(this.enemy_character_position2.getBmp(), 200, 220);
        this.draw.DrawBmp(this.enemy_character_position3.getBmp(), 100, 20);
        this.draw.DrawBmp(this.enemy_character_position4.getBmp(), 100, 170);
        this.draw.DrawBmp(this.enemy_character_position5.getBmp(), 0, 70);
        this.draw.DrawBmp(this.enemy_character_position6.getBmp(), 0, 220);

        this.playerableToPartyCursor1Bmp = new createjs.Bitmap(this.PLAYER_CURSOR_1_PATH);
        this.playerableToPartyCursor1Bmp.scaleX = 0.1;
        this.playerableToPartyCursor1Bmp.scaleY = 0.1;
        var playerableToPartyCursorPositionX = 0;
        var playerableToPartyCursorPositionY = 0;
        
        switch (this._getPlayableCharacter().getToPartyTargetPositionNumber()) {
            case 1:
                playerableToPartyCursorPositionX = this.PARTY_CHARACTER1_POSITION_X + this.PLAYER_CURSOR_RELATIVE_POSITION_X;
                playerableToPartyCursorPositionY = this.PARTY_CHARACTER1_POSITION_Y + this.PLAYER_CURSOR_RELATIVE_POSITION_Y;
                break;
            case 2:
                playerableToPartyCursorPositionX = this.PARTY_CHARACTER2_POSITION_X + this.PLAYER_CURSOR_RELATIVE_POSITION_X;
                playerableToPartyCursorPositionY = this.PARTY_CHARACTER2_POSITION_Y + this.PLAYER_CURSOR_RELATIVE_POSITION_Y;
                break;
            case 3:
                playerableToPartyCursorPositionX = this.PARTY_CHARACTER3_POSITION_X + this.PLAYER_CURSOR_RELATIVE_POSITION_X;
                playerableToPartyCursorPositionY = this.PARTY_CHARACTER3_POSITION_Y + this.PLAYER_CURSOR_RELATIVE_POSITION_Y;
                break;
            case 4:
                playerableToPartyCursorPositionX = this.PARTY_CHARACTER4_POSITION_X + this.PLAYER_CURSOR_RELATIVE_POSITION_X;
                playerableToPartyCursorPositionY = this.PARTY_CHARACTER4_POSITION_Y + this.PLAYER_CURSOR_RELATIVE_POSITION_Y;
                break;
            case 5:
                playerableToPartyCursorPositionX = this.PARTY_CHARACTER5_POSITION_X + this.PLAYER_CURSOR_RELATIVE_POSITION_X;
                playerableToPartyCursorPositionY = this.PARTY_CHARACTER5_POSITION_Y + this.PLAYER_CURSOR_RELATIVE_POSITION_Y;
                break;
            case 6:
                playerableToPartyCursorPositionX = this.PARTY_CHARACTER6_POSITION_X + this.PLAYER_CURSOR_RELATIVE_POSITION_X;
                playerableToPartyCursorPositionY = this.PARTY_CHARACTER6_POSITION_Y + this.PLAYER_CURSOR_RELATIVE_POSITION_Y;
                break;
            case 7:
                playerableToPartyCursorPositionX = this.PARTY_CHARACTER7_POSITION_X + this.PLAYER_CURSOR_RELATIVE_POSITION_X;
                playerableToPartyCursorPositionY = this.PARTY_CHARACTER7_POSITION_Y + this.PLAYER_CURSOR_RELATIVE_POSITION_Y;
                break;
            case 8:
                playerableToPartyCursorPositionX = this.PARTY_CHARACTER8_POSITION_X + this.PLAYER_CURSOR_RELATIVE_POSITION_X;
                playerableToPartyCursorPositionY = this.PARTY_CHARACTER8_POSITION_Y + this.PLAYER_CURSOR_RELATIVE_POSITION_Y;
                break;
        }
        this.draw.DrawBmp(this.playerableToPartyCursor1Bmp, playerableToPartyCursorPositionX, playerableToPartyCursorPositionY);


        //各キャラ用に必要
        this.partyToEnemyCursor1Bmp = new createjs.Bitmap(this.ENEMY_CURSOR_1_PATH);
        this.partyToEnemyCursor1Bmp.scaleX = 0.1;
        this.partyToEnemyCursor1Bmp.scaleY = 0.1;
        var partyToEnemyCursorPositionX = 0;
        var partyToEnemyCursorPositionY = 0;
        switch (this.target_enemy_position_number) {
            case 1:
                partyToEnemyCursorPositionX = this.PARTY_CHARACTER7_POSITION_X + this.PLAYER_CURSOR_RELATIVE_POSITION_X;
                partyToEnemyCursorPositionY = this.PARTY_CHARACTER7_POSITION_Y + this.PLAYER_CURSOR_RELATIVE_POSITION_Y;
                break;
            case 2:
                partyToEnemyCursorPositionX = this.PARTY_CHARACTER7_POSITION_X + this.PLAYER_CURSOR_RELATIVE_POSITION_X;
                partyToEnemyCursorPositionY = this.PARTY_CHARACTER7_POSITION_Y + this.PLAYER_CURSOR_RELATIVE_POSITION_Y;
                break;
            case 3:
                partyToEnemyCursorPositionX = this.PARTY_CHARACTER7_POSITION_X + this.PLAYER_CURSOR_RELATIVE_POSITION_X;
                partyToEnemyCursorPositionY = this.PARTY_CHARACTER7_POSITION_Y + this.PLAYER_CURSOR_RELATIVE_POSITION_Y;
                break;
            case 4:
                partyToEnemyCursorPositionX = this.PARTY_CHARACTER7_POSITION_X + this.PLAYER_CURSOR_RELATIVE_POSITION_X;
                partyToEnemyCursorPositionY = this.PARTY_CHARACTER7_POSITION_Y + this.PLAYER_CURSOR_RELATIVE_POSITION_Y;
                break;
        }
        this.draw.DrawBmp(this.partyToEnemyCursor1Bmp, partyToEnemyCursorPositionX, partyToEnemyCursorPositionY);
        
    }

    _getPlayableCharacter()
    {
        switch (this.playable_party_position_number)
        {
            case 1:
                return this.party_character1;
            case 2:
                return this.party_character2;
            case 3:
                return this.party_character3;
            case 4:
                return this.party_character4;
            case 5:
                return this.party_character5;
            case 6:
                return this.party_character6;
            case 7:
                return this.party_character7;
            case 8:
                return this.party_character8;
        }
    }

    _initPartyDeploy()
    {
        this.party_character1 = this.party_structure.getPartyForBattlePosition1();
        this.party_character1.setToPartyTargetPositionNumber(1);
        this.party_character1.setToEnemyTargetPositionNumber(1);
        this.party_character2 = this.party_structure.getPartyForBattlePosition2();
        this.party_character2.setToPartyTargetPositionNumber(1);
        this.party_character2.setToEnemyTargetPositionNumber(1);
        this.party_character3 = this.party_structure.getPartyForBattlePosition3();
        this.party_character3.setToPartyTargetPositionNumber(1);
        this.party_character3.setToEnemyTargetPositionNumber(1);
        this.party_character4 = this.party_structure.getPartyForBattlePosition4();
        this.party_character4.setToPartyTargetPositionNumber(1);
        this.party_character4.setToEnemyTargetPositionNumber(1);
        this.party_character5 = this.party_structure.getPartyForBattlePosition5();
        this.party_character5.setToPartyTargetPositionNumber(1);
        this.party_character5.setToEnemyTargetPositionNumber(1);
        this.party_character6 = this.party_structure.getPartyForBattlePosition6();
        this.party_character6.setToPartyTargetPositionNumber(1);
        this.party_character6.setToEnemyTargetPositionNumber(1);
        this.party_character7 = this.party_structure.getPartyForBattlePosition7();
        this.party_character7.setToPartyTargetPositionNumber(1);
        this.party_character7.setToEnemyTargetPositionNumber(1);
        this.party_character8 = this.party_structure.getPartyForBattlePosition8();
        this.party_character8.setToPartyTargetPositionNumber(1);
        this.party_character8.setToEnemyTargetPositionNumber(1);
        this.playable_party_id = this.PARTY_NUMBER_ID_BERSERK;
        this.playable_party_position_number = this.party_structure.getPlayablePartyPositionNumber();
    }

    _initEnemyDeploy()
    {
        //多分idを渡してモンスターをインスタンス化するようなfactoryクラスが必要になる予感
        this.enemy_character_position1 = new Goblin;
        this.enemy_character_position2 = new Goblin;
        this.enemy_character_position3 = new Goblin;
        this.enemy_character_position4 = new Goblin;
        this.enemy_character_position5 = new Goblin;
        this.enemy_character_position6 = new Goblin;
    }

    play()
    {
        //入力処理
        this.input();

        //内部計算
         //行動中か同課の確認
        //行動中であればアニメーションを進めてreturn
        //キャラタッチの確認

        //表示
        this.draw.updateStageCreateJS();
    }

    input()
    {
        //メニューを開いたかどうか

        
        //入力処理（プレイアブル
        var selectPositionNumber = 0;

        //イベント登録をループで回しても動かない。
        //インプットクラスが必要
        //initでクリックイベントをすべて登録し、関数はinputフラグをオンにする。
        //inputフラグを見て、どこに入力されているかで処理をする
        //完了後、inputフラグをオフにする。
        /*var rect = new createjs.Shape();
        rect.graphics.beginFill("blue").drawRect(200, 20, 160, 160);
        this.draw.DrawBmp(rect, 1, 1);
        rect.addEventListener("click", handleRectClick);
       function handleRectClick(event) {
            alert("四角形がクリックされました");
        }*/
        

        var partyPosition1RectCollision = this.party_character1.getRectCollision();
        partyPosition1RectCollision.addEventListener("click", selectPartyTarget1);
        function selectPartyTarget1(event) {
            selectPositionNumber = 1;
        }

        var partyPosition2RectCollision = this.party_character2.getRectCollision();
        partyPosition2RectCollision.addEventListener("click", selectPartyTarget2);
        function selectPartyTarget2(event) {
            selectPositionNumber = 2;
        }

        var partyPosition3RectCollision = this.party_character3.getRectCollision();
        partyPosition3RectCollision.addEventListener("click", selectPartyTarget3);
        function selectPartyTarget3(event) {
            selectPositionNumber = 3;
        }

        var partyPosition4RectCollision = this.party_character4.getRectCollision();
        partyPosition4RectCollision.addEventListener("click", selectPartyTarget4);
        function selectPartyTarget4(event) {
            selectPositionNumber = 4;
        }

        var partyPosition5RectCollision = this.party_character5.getRectCollision();
        partyPosition5RectCollision.addEventListener("click", selectPartyTarget5);
        function selectPartyTarget5(event) {
            selectPositionNumber = 5;
        }

        var partyPosition6RectCollision = this.party_character6.getRectCollision();
        partyPosition6RectCollision.addEventListener("click", selectPartyTarget6);
        function selectPartyTarget6(event) {
            selectPositionNumber = 6;
        }

        var partyPosition7RectCollision = this.party_character7.getRectCollision();
        partyPosition7RectCollision.addEventListener("click", selectPartyTarget7);
        function selectPartyTarget7(event) {
            selectPositionNumber = 7;
        }

        var partyPosition8RectCollision = this.party_character8.getRectCollision();
        partyPosition8RectCollision.addEventListener("click", selectPartyTarget8);
        function selectPartyTarget8(event) {
            selectPositionNumber = 8;
        }


        switch (this.playable_party_position_number) {
            case 1://流石にここはマジックナンバーで良いと思うんだけど・・
                this.party_character1.setToPartyTargetPositionNumber(selectPositionNumber);
                break;
            case 2:
                this.party_character2.setToPartyTargetPositionNumber(selectPositionNumber);
                break;
            case 3:
                this.party_character3.setToPartyTargetPositionNumber(selectPositionNumber);
                break;
            case 4:
                this.party_character4.setToPartyTargetPositionNumber(selectPositionNumber);
                break;
            case 5:
                this.party_character5.setToPartyTargetPositionNumber(selectPositionNumber);
                break;
            case 6:
                this.party_character6.setToPartyTargetPositionNumber(selectPositionNumber);
                break;
            case 7:
                this.party_character7.setToPartyTargetPositionNumber(selectPositionNumber);
                break;
            case 8:
                this.party_character8.setToPartyTargetPositionNumber(selectPositionNumber);
                break;
        }


        switch (this._getPlayableCharacter().getToPartyTargetPositionNumber()) {
            case 1:
                this.playerableToPartyCursor1Bmp.x = this.PARTY_CHARACTER1_POSITION_X + this.PLAYER_CURSOR_RELATIVE_POSITION_X;
                this.playerableToPartyCursor1Bmp.y = this.PARTY_CHARACTER1_POSITION_Y + this.PLAYER_CURSOR_RELATIVE_POSITION_Y;
                break;
            case 2:
                this.playerableToPartyCursor1Bmp.x = this.PARTY_CHARACTER2_POSITION_X + this.PLAYER_CURSOR_RELATIVE_POSITION_X;
                this.playerableToPartyCursor1Bmp.y = this.PARTY_CHARACTER2_POSITION_Y + this.PLAYER_CURSOR_RELATIVE_POSITION_Y;
                break;
            case 3:
                this.playerableToPartyCursor1Bmp.x = this.PARTY_CHARACTER3_POSITION_X + this.PLAYER_CURSOR_RELATIVE_POSITION_X;
                this.playerableToPartyCursor1Bmp.y = this.PARTY_CHARACTER3_POSITION_Y + this.PLAYER_CURSOR_RELATIVE_POSITION_Y;
                break;
            case 4:
                this.playerableToPartyCursor1Bmp.x = this.PARTY_CHARACTER4_POSITION_X + this.PLAYER_CURSOR_RELATIVE_POSITION_X;
                this.playerableToPartyCursor1Bmp.y = this.PARTY_CHARACTER4_POSITION_Y + this.PLAYER_CURSOR_RELATIVE_POSITION_Y;
                break;
            case 5:
                this.playerableToPartyCursor1Bmp.x = this.PARTY_CHARACTER5_POSITION_X + this.PLAYER_CURSOR_RELATIVE_POSITION_X;
                this.playerableToPartyCursor1Bmp.y = this.PARTY_CHARACTER5_POSITION_Y + this.PLAYER_CURSOR_RELATIVE_POSITION_Y;
                break;
            case 6:
                this.playerableToPartyCursor1Bmp.x = this.PARTY_CHARACTER6_POSITION_X + this.PLAYER_CURSOR_RELATIVE_POSITION_X;
                this.playerableToPartyCursor1Bmp.y = this.PARTY_CHARACTER6_POSITION_Y + this.PLAYER_CURSOR_RELATIVE_POSITION_Y;
                break;
            case 7:
                this.playerableToPartyCursor1Bmp.x = this.PARTY_CHARACTER7_POSITION_X + this.PLAYER_CURSOR_RELATIVE_POSITION_X;
                this.playerableToPartyCursor1Bmp.y = this.PARTY_CHARACTER7_POSITION_Y + this.PLAYER_CURSOR_RELATIVE_POSITION_Y;
                break;
            case 8:
                this.playerableToPartyCursor1Bmp.x = this.PARTY_CHARACTER8_POSITION_X + this.PLAYER_CURSOR_RELATIVE_POSITION_X;
                this.playerableToPartyCursor1Bmp.y = this.PARTY_CHARACTER8_POSITION_Y + this.PLAYER_CURSOR_RELATIVE_POSITION_Y;
                break;
        }



        //味方CPの処理
        //敵CPの処理
        //コマンドの確認

        
    }

    


}
