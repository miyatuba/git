using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Cursor : MonoBehaviour
{
    private int select_number = 0;

    //座標は入れておく
    private List<float> y_position_list = new List<float>() {
        1.5f, 0.4f, -0.7f, -1.8f
    };

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void SelectCursorChangeByInput(InputManager input_manager)
    {
        if (input_manager.IsUpArrowKey()) {
            this.select_number += 3; 
        }

        if (input_manager.IsDownArrowKey()) {
            this.select_number += 1;
        }

        this.select_number = this.select_number % 4;

        // transformを取得
        Transform transform = this.transform;

        // 座標を取得
        Vector3 position = transform.position;
        position.y = this.y_position_list[this.select_number];
        
        transform.position = position;  // 座標を設定

    }
}
