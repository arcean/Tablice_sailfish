import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    id: mainPage
    property string searchString
    property bool keepSearchFieldFocus
    property string activeView: "list"

    onSearchStringChanged: listModel.update()
    Component.onCompleted: listModel.update()

    Loader {
        anchors.fill: parent
        sourceComponent: listViewComponent
    }

    Column {
        id: headerContainer

        width: mainPage.width

        PageHeader {
            title: "Tablice"
        }

        SearchField {
            id: searchField
            width: parent.width

            Binding {
                target: mainPage
                property: "searchString"
                value: searchField.text.toLowerCase().trim()
            }
        }
    }

    Component {
        id: listViewComponent
        SilicaListView {
//            model: listModel
            model: plateModel
            anchors.fill: parent
            currentIndex: -1 // otherwise currentItem will steal focus
            header:  Item {
                id: header
                width: headerContainer.width
                height: headerContainer.height
                Component.onCompleted: headerContainer.parent = header
            }

            delegate: BackgroundItem {
                id: backgroundItem
                height: Theme.itemSizeLarge

                ListView.onAdd: AddAnimation {
                    target: backgroundItem
                }
                ListView.onRemove: RemoveAnimation {
                    target: backgroundItem
                }

                Label {
                    id: delegateNameLabel
                    x: searchField.textLeftMargin
                    anchors.top: parent.top
                    anchors.topMargin: Theme.paddingSmall
                    color: searchString.length > 0 ? (highlighted ? Theme.secondaryHighlightColor : Theme.secondaryColor)
                                                   : (highlighted ? Theme.highlightColor : Theme.primaryColor)
                    textFormat: Text.StyledText
                    text: {
                        var plate = model.name + "...";
                        Theme.highlightText(plate , searchString, Theme.highlightColor);
                    }
                }
                Label {
                    id: delegateProvinceName
                    x: searchField.textLeftMargin
                    anchors.top: delegateNameLabel.bottom
                    color: highlighted ? Theme.secondaryHighlightColor : Theme.secondaryColor
                    font.pixelSize: Theme.fontSizeTiny
                    textFormat: Text.StyledText
                    text: {
                        var province = "Województwo: " + model.province;

                        Theme.highlightText(province , searchString, Theme.highlightColor);
                    }
                }
                Label {
                    id: delegateCityName
                    x: searchField.textLeftMargin
                    anchors.top: delegateProvinceName.bottom
                    color: highlighted ? Theme.secondaryHighlightColor : Theme.secondaryColor
                    font.pixelSize: Theme.fontSizeTiny
                    textFormat: Text.StyledText
                    text: Theme.highlightText(getCityOrCountyName(model), searchString, Theme.highlightColor);
                }
            }

            VerticalScrollDecorator {}

            Component.onCompleted: {
                if (keepSearchFieldFocus) {
                    searchField.forceActiveFocus()
                }
                keepSearchFieldFocus = false
            }
        }
    }

    function getCityOrCountyName(model) {
        if (model.city === "")
            return "Powiat: " + model.county;
        return "Miasto: " + model.city;
    }

    ListModel {
        id: listModel

        // copied under creative commons license from Wikipedia
        // http://en.wikipedia.org/wiki/List_of_sovereign_states
        property variant countries: ["Afghanistan", "Albania", "Algeria", "Andorra", "Angola",
            "Taiwan"]

        function update() {
            var filteredCountries = countries.filter(function (country) { return country.toLowerCase().indexOf(searchString) !== -1 })
            while (count > filteredCountries.length) {
                remove(filteredCountries.length)
            }
            for (var index = 0; index < filteredCountries.length; index++) {
                if (index < count) {
                    setProperty(index, "text", filteredCountries[index])
                } else {
                    append({ "text": filteredCountries[index]})
                }
            }
        }
    }
}
