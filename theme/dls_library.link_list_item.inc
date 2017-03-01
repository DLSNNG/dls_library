
<?php

  /*************************************************************
   *
   *  @param: display = string
   *  @param: url = string
   *  @returns: drupal render array
   *
   *************************************************************/

  function theme_link_list_item($variables) {
  

    // Validate and set display property
    if((gettype($variables['display']) == 'string')) { 
      $display = $variables['display'];
    }
    else {
      form_set_error('', 'theme link_list_item - display should be string. Received ' . gettype($variables['display']) . '.');
      return;
    }
    // Validate and set url property
    if((gettype($variables['url']) == 'string')) { 
      $url = $variables['url'];
    }
    else {
      form_set_error('', 'theme link_list_item - url should be string. Received ' . gettype($variables['url']) . '.');
      return;
    }

    ///////////////////////////////////////
    //  Render Component
    ///////////////////////////////////////
    
    $block = array(
      '#type' => 'markup',
      '#markup' => $display,
      '#prefix' => '<li><a href="' . $url . '">',
      '#suffix' => '</a></li>',
    );
    return $block;
  }

