
<?php

  /*************************************************************
   *
   *  @param: display = string
   *  @returns: drupal render array
   *
   *************************************************************/

  function theme_list_item($variables) {
  

    // Validate and set display property
    if((gettype($variables['display']) == 'string')) { 
      $display = $variables['display'];
    }
    else {
      form_set_error('', 'theme list_item - display should be string. Received ' . gettype($variables['display']) . '.');
      return;
    }

    ///////////////////////////////////////
    //  Render Component
    ///////////////////////////////////////
    
    $block = array(
      '#type' => 'markup',
      '#markup' => $display,
      '#prefix' => '<li>',
      '#suffix' => '</li>',
    );
    return $block;
  }

