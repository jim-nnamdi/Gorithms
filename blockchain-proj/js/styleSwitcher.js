
(function ($) {
    "use strict"

    const body = $('body');
    const html = $('html');

    //get the DOM elements from right sidebar
    const fontSelect = $('#theme_font');

    //change the theme typography controller
    fontSelect.on('change', function () {
        body.attr('data-font', this.value);
    });

    //change the header background controller
    $('input[name="header_bg"]').on('click', function () {
        body.attr('data-bodybg', this.value);
    });

    //change the nav-header background controller
    $('input[name="navigation_header"]').on('click', function () {
        body.attr('data-primary-color', this.value);
    });


})(jQuery);



