
<?php

  /*************************************************************
   *
   *  @param: display = string
   *  @param: url = string
   *  @param: class = string
   *  @returns: drupal render array
   *
   *************************************************************/

  function theme_custom_button($variables) {
  

    // Validate and set display property
    if((gettype($variables['display']) == 'string')) { 
      $display = $variables['display'];
    }
    else {
      form_set_error('', 'theme button - display should be string. Received ' . gettype($variables['display']) . '.');
      return;
    }
    // Validate and set url property
    if((gettype($variables['url']) == 'string')) { 
      $url = $variables['url'];
    }
    else {
      $url = url(current_path());
    }
    // Validate and set class property
    if((gettype($variables['class']) == 'string')) { 
      $class = $variables['class'];
    }
    else {
      form_set_error('', 'theme button - class should be string. Received ' . gettype($variables['class']) . '.');
      return;
    }

    ///////////////////////////////////////
    //  Render Component
    ///////////////////////////////////////
    
    $block = array(
      '#type' => 'markup',
      '#markup' => $display,
      '#prefix' => '<a href="' . $url . '" class="' . $class . '">',
      '#suffix' => '</a>',
    );
    
    return $block;
  }

