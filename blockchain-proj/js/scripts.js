//  Preloader
jQuery(window).on("load", function () {
    $('#preloader').fadeOut(500);
    $('#main-wrapper').addClass('show');
});


(function ($) {

    "use strict"

    //  Header fixed
    // $(window).scroll(function() {
    //     if ($(this).scrollTop() > 1) {
    //         $('.header').addClass("animated slideInDown fixed"), 3000;
    //     } else {
    //         $('.header').removeClass("animated slideInDown fixed"), 3000;
    //     }
    // });

    $('.duration-option a')
        .on('click', function () {
            $(".duration-option a.active")
                .removeClass("active");
            $(this)
                .addClass('active');
        });


    // Custom Selectbox

    $('.drop-menu').click(function () {
        $(this).attr('tabindex', 1).focus();
        $(this).toggleClass('active');
        $(this).find('.dropeddown').slideToggle(300);
    });
    $('.drop-menu').focusout(function () {
        $(this).removeClass('active');
        $(this).find('.dropeddown').slideUp(300);
    });
    $('.drop-menu .dropeddown li').click(function () {
        $(this).parents('.drop-menu').find('span').text($(this).text());
        $(this).parents('.drop-menu').find('input').attr('value', $(this).attr('id'));
    });


    // File Upload 
    $(".file-upload-wrapper").on("change", ".file-upload-field", function () {
        $(this).parent(".file-upload-wrapper").attr("data-text", $(this).val().replace(/.*(\/|\\)/, ''));
    });


    //to keep the current page active
    $(function () {
        for (var nk = window.location,
            o = $(".menu a").filter(function () {
                return this.href == nk;
            })
                .addClass("active")
                .parent()
                .addClass("active"); ;) {
            // console.log(o)
            if (!o.is("li")) break;
            o = o.parent()
                .addClass("show")
                .parent()
                .addClass("active");
        }

    });

    // $(function() {
    //     // var win_w = window.outerWidth;
    //     var win_h = window.outerHeight;
    //     var win_h = window.outerHeight;
    //     if (win_h > 0 ? win_h : screen.height) {
    //         $(".authincation").css("min-height", (win_h + 60) + "px");
    //     };
    // });

    // $('[data-toggle="tooltip"]').tooltip();

    $('.sidebar-right-trigger').on('click', function () {
        $('.sidebar-right').toggleClass('show');
    });






})(jQuery);











//ripple effect on button
Waves.init();
Waves.attach('.wave-effect');
Waves.attach('.btn');
Waves.attach('button');