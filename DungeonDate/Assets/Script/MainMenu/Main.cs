using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Main : MonoBehaviour
{
    public GameObject input_obj;
    public GameObject cursor_obj;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        this.input_obj.GetComponent<InputManager>().InputCheck();

        this.cursor_obj.GetComponent<Cursor>().SelectCursorChangeByInput(this.input_obj.GetComponent<InputManager>());


        this.input_obj.GetComponent<InputManager>().LoopReset();
    }
}
