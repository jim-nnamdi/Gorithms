
var body = $('body');
var html = $('html');

function quixSettings({ fontFamily, bodybg, primarycolor }) {
    this.fontFamily = fontFamily || "light";
    this.bodybg = bodybg || "color_1";
    this.primarycolor = primarycolor || "color_1";

    this.manageFont();
    this.manageBodyBg();
    this.primaryColor();

}

quixSettings.prototype.manageFont = function() {
    switch(this.fontFamily) {
        case "opensans": 
            body.attr("data-font", "opensans");
            break;
        default: 
            body.attr("data-font", "nunito");
    }
}

quixSettings.prototype.manageBodyBg = function () {
    switch (this.bodybg) {
        case "color_1":
            body.attr("data-bodybg", "color_1");
            break;
        case "color_2":
            body.attr("data-bodybg", "color_2");
            break;
        case "color_3":
            body.attr("data-bodybg", "color_3");
            break;
        case "color_4":
            body.attr("data-bodybg", "color_4");
            break;
        case "color_5":
            body.attr("data-bodybg", "color_5");
            break;
        default:
            body.attr("data-bodybg", "color_1");
    }
}


quixSettings.prototype.primaryColor = function() {
    switch(this.primarycolor) {
        case "color_1": 
            body.attr("data-primary-color", "color_1");
            break;
        case "color_2": 
            body.attr("data-primary-color", "color_2");
            break;
        case "color_3": 
            body.attr("data-primary-color", "color_3");
            break;
        case "color_4": 
            body.attr("data-primary-color", "color_4");
            break;
        case "color_5": 
            body.attr("data-primary-color", "color_5");
            break;
        default:
            body.attr("data-primary-color", "color_1");
    }
}

