using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;

public class Delete : MonoBehaviour
{
    private bool is_delete_mode = false;

    public Text delete_mode_text;
    public EventSystem event_system;

    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetMouseButtonUp(0))
        {


            if (this.event_system.currentSelectedGameObject != null)
            {

                if (this.event_system.currentSelectedGameObject.name == "Delete")
                {
                    if (this.is_delete_mode == true)
                    {
                        this.is_delete_mode = false;
                        delete_mode_text.gameObject.SetActive(false);
                    }
                    else
                    {
                        this.is_delete_mode = true;
                        delete_mode_text.gameObject.SetActive(true);
                    }
                }

            }
        }
    }

    public bool isDeleteMode()
    {
        return this.is_delete_mode;
    }
}
