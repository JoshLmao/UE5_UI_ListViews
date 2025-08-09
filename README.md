# UE5_UI_ListViews

A project that uses Common UI and basic list views to show off how to properly use and structure them. The focus of this
project is to demonstrate how to properly use List Views and support many use cases,
such as focus handling, scrolling, and showing off different features List Views offer.

## Structure

- List View: The main container for displaying many items of data. Handles virtualization and scrolling via a ScrollBox,
  where necessary
- List Item: A single instance of a `UObject`, with data. You subclass a `UObject` and populate with data
- List Entry: A `UUserWidget` that gets populated inside of a `UListView`